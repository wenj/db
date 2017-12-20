%{
#include "Tree.h"
%}

%start Program

%union{
    int intVal;
    char *stringVal;
    Tree::Op *opVal;
    Tree::Identifier *identVal;
    Tree *tree;
}

/* 抄的，我也不明白这些在干什么 */
%token <ival> VALUE_INT
%token <sval> VALUE_STRING
%type <cval> Op
%type <tree> Program Stmt SysStmt DbStmt TbStmt IdxStmt Field Type WhereClause SetClause

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
			        $$.tree = new Tree();
			        $$.tree->stmtList = new std::list<Stmt*>();
			    }
			    |   Program Stmt
			    {
			        $$.tree->stmtList->push_back($2);
			    }
			    ;

Stmt            :   SysStmt ';'
                {
                    $$.tree = $1.tree;
                }
	            |   DbStmt ';'
	            {
                    $$.tree = $1.tree;
                }
	            |   TbStmt ';'
	            {
                    $$.tree = $1.tree;
                }
	            |   IdxStmt ';'
	            {
                    $$.tree = $1.tree;
                }
	            ;

SysStmt         :   SHOW DATABASES
                {
                    $$.tree = new SysStmt();
                }

DbStmt          :   CREATE DATABASE DbName
                {
                    $$.tree = new DbStmt((Identifier*) $3.tree);
                }
	            |   DROP DATABASE DbName
	            |   USE DbName
	            |   SHOW TABLES
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

ValueLists      :   '(' ValueList ')'
		        |   ValueLists ',' ValueList
		        ;

ValueList       :   Value
                |   ValueList ',' Value
		        ;

Value           :   VALUE_INT
                |   VALUE_STRING
	            |   NULL
	            ;

WhereClause     :   Col Op Expr
			    |   Col IS NOT NULL
			    |   WhereClause AND WhereClause
			    ;

Col             :   TbName '.' ColName
	            ;

Op              :   EQ
                |   NQ
                |   LT
                |   LE
                |   GT
                |   GE
                ;

Expr            :   Value
	            |   Col
	            ;

SetClause       :   ColName EQ Value
		        |   SetClause ',' ColName EQ Value
		        ;


Selector        :   '*'
		        |   ColList
		        ;

ColList         :   Col
		        |   ColList Col
		        ;

TableList       :   TbName
		        |   TableList ',' TbName
		        ;

ColumnList      :   ColName
		        |   ColumnList ',' ColName
		        ;

DbName          :   IDENTIFIER
                {
                    $$.tree = new Identifier();
                }

TbName          :   IDENTIFIER

ColName         :   IDENTIFIER