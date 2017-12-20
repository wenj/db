#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
#include "Tree.h"
#line 7 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
typedef union{
    int intVal;
    char *stringVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;
} YYSTYPE;
#line 22 "y.tab.c"
#define VALUE_INT 257
#define VALUE_STRING 258
#define IDENTIFIER 259
#define EQ 260
#define NE 261
#define LT 262
#define LE 263
#define GT 264
#define GE 265
#define DATABASE 266
#define DATABASES 267
#define TABLE 268
#define TABLES 269
#define SHOW 270
#define CREATE 271
#define DROP 272
#define USE 273
#define PRIMARY 274
#define KEY 275
#define NOT 276
#define NULL 277
#define INSERT 278
#define INTO 279
#define VALUES 280
#define DELETE 281
#define FROM 282
#define WHERE 283
#define UPDATE 284
#define SET 285
#define SELECT 286
#define IS 287
#define INT 288
#define VARCHAR 289
#define DESC 290
#define INDEX 291
#define AND 292
#define DATE 293
#define FLOAT 294
#define FOREIGN 295
#define REFERENCES 296
#define NQ 297
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    5,    5,    5,    5,    6,    7,    7,    7,
    7,    8,    8,    8,    8,    8,    8,    8,    9,    9,
   23,   23,   10,   10,   10,   10,   11,   11,   11,   11,
   12,   12,   12,   24,    1,    1,    1,    1,    1,    1,
   21,   21,   13,   13,   14,   18,   18,   20,   20,   19,
   19,   22,   22,   17,   17,   16,   16,   15,   15,   15,
    2,    3,    4,
};
short yylen[] = {                                         2,
    0,    2,    2,    2,    2,    2,    2,    3,    3,    2,
    2,    6,    3,    2,    5,    5,    6,    6,    6,    6,
    1,    3,    2,    4,    5,   10,    2,    2,    1,    1,
    3,    4,    3,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    1,    1,    1,    3,    1,
    3,    3,    1,    3,    3,    1,    3,    1,    1,    1,
    1,    1,    1,
};
short yydefred[] = {                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    0,    0,    0,    0,    7,   11,    0,    0,    0,
    0,    0,    0,   61,   10,    0,    0,   62,    0,    0,
   46,    0,   53,    0,    0,   50,   14,    3,    4,    5,
    6,    8,    0,    0,    9,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   63,    0,
    0,   43,   52,   48,    0,   51,    0,    0,    0,   21,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,   30,    0,
   12,    0,   19,   20,   58,   59,   60,   56,    0,    0,
    0,    0,   35,   37,   38,   39,   40,    0,   36,    0,
   45,    0,   44,    0,   49,    0,    0,   27,   28,    0,
   22,   54,    0,    0,   34,    0,    0,   41,   31,   42,
    0,    0,   24,   57,   32,   25,    0,    0,    0,    0,
    0,   26,
};
short yydgoto[] = {                                       1,
  110,   25,   32,   33,   11,   12,   13,   14,   15,   70,
   90,   77,   61,   62,   98,   99,   75,   34,   35,   65,
  129,   36,   71,   78,
};
short yysindex[] = {                                      0,
 -199, -207, -230, -226, -251, -263, -265, -237,  -36, -237,
    0,  -20,  -15,  -14,   -7,    0,    0, -251, -237, -237,
 -251, -237, -237,    0,    0, -237, -237,    0, -215,    0,
    0,   42,    0, -202,   46,    0,    0,    0,    0,    0,
    0,    0,   55,   56,    0,    0,   57, -180, -182, -157,
 -157, -237, -155, -240, -157, -157,   65, -237,    0, -154,
  -43,    0,    0,    0,  -40,    0, -168, -167, -195,    0,
   -9,   69,   70, -200,   72,   63, -179, -250, -200, -237,
 -157, -237, -237,   74,   77, -145, -139,    0,    0, -156,
    0, -240,    0,    0,    0,    0,    0,    0,   10, -200,
 -157, -237,    0,    0,    0,    0,    0, -153,    0, -209,
    0, -179,    0, -179,    0, -155, -157,    0,    0, -158,
    0,    0, -200,   78,    0, -179, -152,    0,    0,    0,
   25,   80,    0,    0,    0,    0, -172, -237,   86, -157,
   87,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -41,
    0,    0,    0,    0, -151,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   71,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   75,    0,   76,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   79,    0,   81,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
    0,   68,    1,  -25,    0,    0,    0,    0,    0,   35,
    0,  -39,    0,   48,  -77,   33,    0,    0,   20,    0,
    0,  -46,    0,    0,
};
#define YYTABLESIZE 251
short yytable[] = {                                      63,
   81,  111,   63,   83,   62,   31,   66,   24,   29,  103,
   37,  104,  105,  106,  107,   26,   27,   63,   59,   43,
   44,   28,   46,   47,   60,   63,   48,   49,   69,   72,
   73,   91,  128,   67,   92,   18,  108,   19,   38,   21,
  112,   22,  114,   39,   40,  134,  109,   95,   96,   30,
  122,   41,   64,  123,   68,   60,   95,   96,   76,   16,
   20,   17,  126,  130,   23,  136,   69,   97,   53,   50,
    2,    3,    4,    5,   23,  125,   97,   23,    6,   52,
   76,    7,   76,  115,    8,   42,    9,   51,   45,   53,
   10,  132,   86,   87,   54,   55,   56,   88,   89,   57,
   58,   59,   76,   30,   74,   79,   84,   85,  101,   93,
   94,  118,  102,  116,  141,  100,  117,  119,  133,  120,
  137,  123,  127,  138,  135,  140,  121,  142,  113,   15,
   47,   16,  124,   17,   18,  131,    0,   55,  139,   33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   63,    0,   82,    0,    0,    0,    0,    0,    0,    0,
   63,
};
short yycheck[] = {                                      41,
   44,   79,   44,   44,   46,   42,   53,  259,    8,  260,
   10,  262,  263,  264,  265,  279,  282,   59,  259,   19,
   20,  259,   22,   23,   50,   51,   26,   27,   54,   55,
   56,   41,  110,  274,   44,  266,  287,  268,   59,  266,
   80,  268,   82,   59,   59,  123,  297,  257,  258,  259,
   41,   59,   52,   44,  295,   81,  257,  258,   58,  267,
  291,  269,  102,  110,  291,   41,   92,  277,   44,  285,
  270,  271,  272,  273,   41,  101,  277,   44,  278,  282,
   80,  281,   82,   83,  284,   18,  286,   46,   21,   44,
  290,  117,  288,  289,   40,   40,   40,  293,  294,  280,
  283,  259,  102,  259,   40,  260,  275,  275,   46,   41,
   41,  257,  292,   40,  140,   44,   40,  257,  277,  276,
   41,   44,  276,  296,  277,   40,   92,   41,   81,   59,
  282,   59,  100,   59,   59,  116,   -1,   59,  138,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,
  282,   -1,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  292,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"VALUE_INT","VALUE_STRING","IDENTIFIER","EQ","NE","LT","LE","GT","GE",
"DATABASE","DATABASES","TABLE","TABLES","SHOW","CREATE","DROP","USE","PRIMARY",
"KEY","NOT","NULL","INSERT","INTO","VALUES","DELETE","FROM","WHERE","UPDATE",
"SET","SELECT","IS","INT","VARCHAR","DESC","INDEX","AND","DATE","FLOAT",
"FOREIGN","REFERENCES","NQ",
};
char *yyrule[] = {
"$accept : Program",
"Program :",
"Program : Program Stmt",
"Stmt : SysStmt ';'",
"Stmt : DbStmt ';'",
"Stmt : TbStmt ';'",
"Stmt : IdxStmt ';'",
"SysStmt : SHOW DATABASES",
"DbStmt : CREATE DATABASE DbName",
"DbStmt : DROP DATABASE DbName",
"DbStmt : USE DbName",
"DbStmt : SHOW TABLES",
"TbStmt : CREATE TABLE TbName '(' FieldList ')'",
"TbStmt : DROP TABLE TbName",
"TbStmt : DESC TbName",
"TbStmt : INSERT INTO TbName VALUES ValueLists",
"TbStmt : DELETE FROM TbName WHERE WhereClause",
"TbStmt : UPDATE TbName SET SetClause WHERE WhereClause",
"TbStmt : SELECT Selector FROM TableList WHERE WhereClause",
"IdxStmt : CREATE INDEX TbName '(' ColName ')'",
"IdxStmt : DROP INDEX TbName '(' ColName ')'",
"FieldList : Field",
"FieldList : FieldList ',' Field",
"Field : ColName Type",
"Field : ColName Type NOT NULL",
"Field : PRIMARY KEY '(' ColumnList ')'",
"Field : FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'",
"Type : INT VALUE_INT",
"Type : VARCHAR VALUE_INT",
"Type : DATE",
"Type : FLOAT",
"WhereClause : Col Op Expr",
"WhereClause : Col IS NOT NULL",
"WhereClause : WhereClause AND WhereClause",
"Col : TbName '.' ColName",
"Op : EQ",
"Op : NQ",
"Op : LT",
"Op : LE",
"Op : GT",
"Op : GE",
"Expr : Value",
"Expr : Column",
"SetClause : SingleSetClause",
"SetClause : SetClause ',' SingleSetClause",
"SingleSetClause : ColName EQ Value",
"Selector : '*'",
"Selector : ColumnList",
"TableList : TbName",
"TableList : TableList ',' TbName",
"ColumnList : Column",
"ColumnList : ColumnList ',' Column",
"Column : TbName '.' ColName",
"Column : ColName",
"ValueLists : '(' ValueList ')'",
"ValueLists : ValueLists ',' ValueList",
"ValueList : Value",
"ValueList : ValueList ',' Value",
"Value : VALUE_INT",
"Value : VALUE_STRING",
"Value : NULL",
"DbName : IDENTIFIER",
"TbName : IDENTIFIER",
"ColName : IDENTIFIER",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 43 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new Tree();
			    }
break;
case 2:
#line 47 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree->stmtList.push_back((Stmt*) yyvsp[0].tree);
			    }
break;
case 3:
#line 53 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 4:
#line 57 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 5:
#line 61 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 6:
#line 65 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 7:
#line 71 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SysStmt();
                }
break;
case 8:
#line 76 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateDbStmt(yyvsp[0].identVal);
                }
break;
case 9:
#line 80 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DropDbStmt(yyvsp[0].identVal);
	            }
break;
case 10:
#line 84 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UseDbStmt(yyvsp[0].identVal);
	            }
break;
case 11:
#line 88 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ShowDbStmt();
	            }
break;
case 41:
#line 139 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new ValueExpr((Value*) yyvsp[0].tree);
                }
break;
case 42:
#line 143 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ColExpr((Column*) yyvsp[0].tree);
	            }
break;
case 43:
#line 149 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    std::list<SingleSetClause> singleList;
                    singleList.push_back(yyvsp[0].tree);
                    yyval.tree = new SetClause(&singleList);
                }
break;
case 44:
#line 155 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            std::list<SingleSetClause>* beforeList = ((SetClause*) yyvsp[-2].tree)->getSetClauseList();
		            std::list<SingleSetClause> singleList;
		            singleList.insert(singleList.end(), beforeList->begin(), beforeList->end());
		            singleList.push_back(yyvsp[0].tree);
		            yyval.tree = new SetClause(&singleList);
		        }
break;
case 45:
#line 165 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SingleSetClause(yyvsp[-2].identVal, yyvsp[0].tree);
                }
break;
case 46:
#line 170 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    /* Tree.columnList 是空的*/
                }
break;
case 47:
#line 174 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList = yyvsp[0].tree->columnList;
		        }
break;
case 48:
#line 181 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->tableList.push_back(yyvsp[0].identVal);
                }
break;
case 49:
#line 186 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->tableList.insert(yyval.tree->tableList.end(), yyvsp[-2].tree->tableList.begin(), yyvsp[-2].tree->tableList.end());
		            yyval.tree->tableList.push_back(yyvsp[0].identVal);
		        }
break;
case 50:
#line 194 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->columnList.push_back(yyvsp[0].tree);
                }
break;
case 51:
#line 199 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList.insert(yyval.tree->columnList.end(), yyvsp[-2].tree->columnList.begin(), yyvsp[-2].tree->columnList.end());
		            yyval.tree->columnList.push_back(yyvsp[0].tree);
		        }
break;
case 52:
#line 207 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[-2].identVal, yyvsp[0].identVal);
                }
break;
case 53:
#line 211 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[0].identVal);
                }
break;
case 54:
#line 217 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueLists.push_back(yyvsp[-1].tree->valueList);
                }
break;
case 55:
#line 222 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
                    yyval.tree->valueLists.insert(yyval.tree->valueLists.end(), yyvsp[-2].tree->valueLists.begin(), yyvsp[-2].tree->valueLists.end());
                    yyval.tree->valueLists.push_back(yyvsp[0].tree->valueList);
		        }
break;
case 56:
#line 230 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.push_back(yyvsp[0].tree);
                }
break;
case 57:
#line 235 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.insert(yyval.tree->valueList.end(), yyvsp[-2].tree->valueList.begin(), yyvsp[-2].tree->valueList.end());
                    yyval.tree->valueList.push_back(yyvsp[0].tree);
                }
break;
case 58:
#line 243 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntValue(yyvsp[0].intVal.intVal);
                }
break;
case 59:
#line 247 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new StringValue(yyvsp[0].stringVal.stringVal);
                }
break;
case 60:
#line 251 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new NullValue();
	            }
break;
case 61:
#line 257 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = yyvsp[0].tree;
                }
break;
case 62:
#line 262 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = yyvsp[0].tree;
                }
break;
case 63:
#line 267 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = yyvsp[0].tree;
                }
break;
#line 673 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
