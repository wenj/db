%{
#include "Tree.h"
%}

%start Program

%union{
    int intVal;
    char *stringVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;
}

/* 抄的，我也不明白这些在干什么
* 好像规定了type之后，就不用调用$$.tree了，可以直接用$$之类的
*/
%token      <intVal>        VALUE_INT
%token      <stringVal>     VALUE_STRING
%type       <opVal>         Op
%type       <identVal>      DbName          TbName          ColName
%type       <tree>          Program         Stmt            SysStmt         DbStmt          TbStmt          IdxStmt
                            Field           Type            WhereClause     SetClause       SingleSetClause Value
                            ValueList       ValueLists      Selector        ColumnList      TableList       IDENTIFIER
                            Expr            Column

%token EQ
%token NE
%token LT
%token LE
%token GT
%token GE
%token DATABASE DATABASES TABLE TABLES SHOW CREATE
%token DROP USE PRIMARY KEY NOT NULL
%token INSERT INTO VALUES DELETE FROM WHERE
%token UPDATE SET SELECT IS INT VARCHAR
%token DESC INDEX AND DATE FLOAT FOREIGN
%token REFERENCES

%%

Program         :   /* empty */
			    {
			        $$ = new Tree();
			    }
			    |   Program Stmt
			    {
			        $$->stmtList.push_back((Stmt*) $2);
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
                |   DROP TABLE TbName
	            |   DESC TbName
	            |   INSERT INTO TbName VALUES ValueLists
	            |   DELETE FROM TbName WHERE WhereClause
	            |   UPDATE TbName SET SetClause WHERE WhereClause
	            |   SELECT Selector FROM TableList WHERE WhereClause
	            ;

IdxStmt         :   CREATE INDEX TbName '(' ColName ')'
                |   DROP INDEX TbName '(' ColName ')'
		        ;

FieldList       :   Field
		        |   FieldList ',' Field
		        ;

Field           :   ColName Type
                |   ColName Type NOT NULL
	            |   PRIMARY KEY '(' ColumnList ')'
	            |   FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'
	            ;

Type            :   INT VALUE_INT
	            |   VARCHAR VALUE_INT
	            |   DATE
	            |   FLOAT
	            ;

WhereClause     :   Col Op Expr
			    |   Col IS NOT NULL
			    |   WhereClause AND WhereClause
			    ;

Col             :   TbName '.' ColName
	            ;

Op              :   EQ
                |   NQ
                {
                    $$ = new Op(Tree.GE);
                }
                |   LT
                {
                    $$ = new Op(Tree.LT);
                }
                |   LE
                {
                    $$ = new Op(Tree.LE);
                }
                |   GT
                {
                    $$ = new Op(Tree.GT);
                }
                |   GE
                {
                    $$ = new Op(Tree.GE);
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
                    $$ = new SingleSetClause($1, $3);
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
                    $$->columnList.push_back($1);
                }
		        |   ColumnList ',' Column
		        {
		            $$ = new Tree();
		            $$->columnList.insert($$->columnList.end(), $1->columnList.begin(), $1->columnList.end());
		            $$->columnList.push_back($3);
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
                    $$->valueList.push_back($1);
                }
                |   ValueList ',' Value
                {
                    $$ = new Tree();
                    $$->valueList.insert($$->valueList.end(), $1->valueList.begin(), $1->valueList.end());
                    $$->valueList.push_back($3);
                }
		        ;

Value           :   VALUE_INT
                {
                    $$ = new IntValue($1.intVal);
                }
                |   VALUE_STRING
                {
                    $$ = new StringValue($1.stringVal);
                }
	            |   NULL
	            {
	                $$ = new NullValue();
	            }
	            ;

DbName          :   IDENTIFIER
                {
                    $$ = $1;
                }

TbName          :   IDENTIFIER
                {
                    $$ = $1;
                }

ColName         :   IDENTIFIER
                {
                    $$ = $1;
                }