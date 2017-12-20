%start Program

%union{
    int ival;
    CompOp cval;
    float rval;
    char *sval;
    Tree *n;
}

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
			    }
			    |   Program Stmt
			    {
			    }
			    ;

Stmt            :   SysStmt ';'
	            |   DbStmt ';'
	            |   TbStmt ';'
	            |   IdxStmt ';'
	            ;

SysStmt         :   SHOW DATABASES

DbStmt          :   CREATE DATABASE DbName
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

TbName          :   IDENTIFIER

ColName         :   IDENTIFIER