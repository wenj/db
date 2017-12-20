%{
#include "YYSTYPE.h"
#include "Tree.h"
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
#include "sm.h"
// #include "ql.h"
#include <iostream>

%}

%start Program

/*
%union{
    int intVal;
    char *stringVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;
}*/

/* 抄的，我也不明白这些在干什么
* 好像规定了type之后，就不用调用$$.tree了，可以直接用$$之类的
*/
%token      <intVal>        VALUE_INTEGER
%token      <stringVal>     VALUE_STRING
%type       <opVal>         Op
%type       <identVal>      DbName          TbName          ColName
%type       <tree>          Program         Stmt            SysStmt         DbStmt          TbStmt          IdxStmt
                            Field           Type            WhereClause     SetClause       SingleSetClause Value
                            ValueList       ValueLists      Selector        ColumnList      TableList       IDENTIFIER
                            Expr            Column          FieldList

%token EQ
%token NE
%token LT
%token LE
%token GT
%token GE
%token DATABASE DATABASES TABLE TABLES SHOW CREATE
%token DROP USE PRIMARY KEY NOT NULL_D
%token INSERT INTO VALUES DELETE FROM WHERE
%token UPDATE SET SELECT IS INT_D VARCHAR  /* INT FLOAT NULL 都不能直接作为token…… */
%token DESC INDEX AND DATE FLOAT_D FOREIGN
%token REFERENCES
%token EOF /* patch for lexer.cc */

%%

Program         :   /* empty */
			    {
			        $$ = new Tree();
			    }
			    |   Program Stmt
			    {
			        $$->stmtList.push_back((Stmt*) $2);
			    }
			    |   EOF
			    {
			        $$ = nullptr;
			    }
			    ;

Stmt            :   SysStmt ';'
                {
                    $$ = $1;
                }
	            |   DbStmt ';'
	            {
                    $$ = $1;
                }
	            |   TbStmt ';'
	            {
                    $$ = $1;
                }
	            |   IdxStmt ';'
	            {
                    $$ = $1;
                }
	            ;

SysStmt         :   SHOW DATABASES
                {
                    $$ = new SysStmt();
                }

DbStmt          :   CREATE DATABASE DbName
                {
                    $$ = new CreateDbStmt($3);
                }
	            |   DROP DATABASE DbName
	            {
	                $$ = new DropDbStmt($3);
	            }
	            |   USE DbName
	            {
	                $$ = new UseDbStmt($2);
	            }
	            |   SHOW TABLES
	            {
	                $$ = new ShowDbStmt();
	            }
	            ;

TbStmt          :   CREATE TABLE TbName '(' FieldList ')'
                {
                    $$ = new CreateTbStmt($3, &$5->fieldList);
                }
                |   DROP TABLE TbName
                {
                    $$ = new DropTbStmt($3);
                }
	            |   DESC TbName
	            {
	                $$ = new DescTbStmt($2);
	            }
	            |   INSERT INTO TbName VALUES ValueLists
	            {
	                $$ = new InsertTbStmt($3, &$5->valueList);
	            }
	            |   DELETE FROM TbName WHERE WhereClause
	            {
	                $$ = new DeleteTbStmt($3, (WhereClause*) $5);
	            }
	            |   UPDATE TbName SET SetClause WHERE WhereClause
	            {
	                $$ = new UpdateTbStmt($2, (SetClause*) $4, (WhereClause*) $6);
	            }
	            |   SELECT Selector FROM TableList WHERE WhereClause
	            {
	                $$ = new SelectTbStmt(&$2->columnList, &$4->tableList, (WhereClause*) $6);
	            }
	            ;

IdxStmt         :   CREATE INDEX TbName '(' ColName ')'
                {
                    $$ = new CreateIdxStmt($3, $5);
                }
                |   DROP INDEX TbName '(' ColName ')'
                {
                    $$ = new DropIdxStmt($3, $5);
                }
		        ;

FieldList       :   Field
                {
                    $$ = new Tree();
                    $$->fieldList.push_back((Field*) $1);
                }
		        |   FieldList ',' Field
		        {
		            $$ = new Tree();
		            $$->fieldList.insert($$->fieldList.end(), $1->fieldList.begin(), $1->fieldList.end());
                    $$->fieldList.push_back((Field*) $3);
		        }
		        ;

/* 问题：是不是这里该干脆把ColName都改成Column */
Field           :   ColName Type
                {
                    $$ = new NormalField((Identifier*) $1, (Type*) $2);
                }
                |   ColName Type NOT NULL_D
                {
                    $$ = new NotNullField((Identifier*) $1, (Type*) $2);
                }
	            |   PRIMARY KEY '(' ColumnList ')'  /* 这里好像从colName变成colList了。。 */
	            {
	                $$ = new PrimaryField(&($4->columnList));
	            }
	            |   FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'  /* TODO: 这应该也是扩展功能，随便加上了 */
	            {
	                $$ = new ForeignField($4, $7, $9);
	            }
	            ;

Type            :   INT_D VALUE_INTEGER
                {
                    $$ = new IntType($2);
                }
	            |   VARCHAR VALUE_INTEGER
	            {
	                $$ = new VarcharType($2);
	            }
	            /*
	            TODO: 这是扩展功能吗？？
	            |   DATE
	            |   FLOAT
	            */
	            ;

WhereClause     :   Column Op Expr
                {
                    $$ = new NormalWhereClause((Column*) $1, (Op*) $2, (Expr*) $3);
                }
			    |   Column IS NULL_D
			    {
			        $$ = new IsNullWhereClause((Column*) $1, false);
			    }
			    |   Column IS NOT NULL_D
			    {
			        $$ = new IsNullWhereClause((Column*) $1, true);
			    }
			    |   WhereClause AND WhereClause
			    {
			        $$ = new AndWhereClause((WhereClause*) $1, (WhereClause*) $3);
			    }
			    ;

Op              :   EQ
                {
                    $$ = new Op(Tree::OP_EQ);
                }
                |   NE
                {
                    $$ = new Op(Tree::OP_NE);
                }
                |   LT
                {
                    $$ = new Op(Tree::OP_LT);
                }
                |   LE
                {
                    $$ = new Op(Tree::OP_LE);
                }
                |   GT
                {
                    $$ = new Op(Tree::OP_GT);
                }
                |   GE
                {
                    $$ = new Op(Tree::OP_GE);
                }
                ;

Expr            :   Value
                {
                    $$ = new ValueExpr((Value*) $1);
                }
	            |   Column
	            {
	                $$ = new ColExpr((Column*) $1);
	            }
	            ;

SetClause       :   SingleSetClause
                {
                    std::list<SingleSetClause*> singleList;
                    singleList.push_back((SingleSetClause*) $1);
                    $$ = new SetClause(&singleList);
                }
		        |   SetClause ',' SingleSetClause
		        {
		            std::list<SingleSetClause*>* beforeList = ((SetClause*) $1)->getSetClauseList();
		            std::list<SingleSetClause*> singleList;
		            singleList.insert(singleList.end(), beforeList->begin(), beforeList->end());
		            singleList.push_back((SingleSetClause*) $3);
		            $$ = new SetClause(&singleList);
		        }
		        ;

SingleSetClause :   ColName EQ Value
                {
                    $$ = new SingleSetClause($1, (Value*) $3);
                }

Selector        :   '*'
                {
                    // Tree.columnList 是空的
                }
		        |   ColumnList
		        {
		            $$ = new Tree();
		            $$->columnList = $1->columnList;
		        }
		        ;

TableList       :   TbName
                {
                    $$ = new Tree();
                    $$->tableList.push_back($1);
                }
		        |   TableList ',' TbName
		        {
		            $$ = new Tree();
		            $$->tableList.insert($$->tableList.end(), $1->tableList.begin(), $1->tableList.end());
		            $$->tableList.push_back($3);
		        }
		        ;

ColumnList      :   Column
                {
                    $$ = new Tree();
                    $$->columnList.push_back((Column*) $1);
                }
		        |   ColumnList ',' Column
		        {
		            $$ = new Tree();
		            $$->columnList.insert($$->columnList.end(), $1->columnList.begin(), $1->columnList.end());
		            $$->columnList.push_back((Column*) $3);
		        }
		        ;

Column          :   TbName '.' ColName
                {
                    $$ = new Column($1, $3);
                }
                |   ColName
                {
                    $$ = new Column($1);
                }
                ;

ValueLists      :   '(' ValueList ')'
                {
                    $$ = new Tree();
                    $$->valueLists.push_back($2->valueList);
                }
		        |   ValueLists ',' ValueList
		        {
		            $$ = new Tree();
                    $$->valueLists.insert($$->valueLists.end(), $1->valueLists.begin(), $1->valueLists.end());
                    $$->valueLists.push_back($3->valueList);
		        }
		        ;

ValueList       :   Value
                {
                    $$ = new Tree();
                    $$->valueList.push_back((Value*) $1);
                }
                |   ValueList ',' Value
                {
                    $$ = new Tree();
                    $$->valueList.insert($$->valueList.end(), $1->valueList.begin(), $1->valueList.end());
                    $$->valueList.push_back((Value*) $3);
                }
		        ;

Value           :   VALUE_INTEGER
                {
                    $$ = new IntValue($1);
                }
                |   VALUE_STRING
                {
                    $$ = new StringValue($1);
                }
	            |   NULL_D
	            {
	                $$ = new NullValue();
	            }
	            ;

DbName          :   VALUE_STRING
                {
                    $$ = new Identifier($1);
                }

TbName          :   VALUE_STRING
                {
                    $$ = new Identifier($1);
                }

ColName         :   VALUE_STRING
                {
                    $$ = new Identifier($1);
                }

%%

extern "C" {
    int yyparse(void);
    int yylex(void);
}

// 以下是抄来的
/*
 * Required by yacc
 */
void yyerror(char const *s) // New in 2000
{
    std::cout << s << std::endl;
}

#if 0
/*
 * Sometimes required
 */
int yywrap(void)
{
    return 1;
}
#endif