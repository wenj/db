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
#include "YYSTYPE.h"
#include "Tree.h"
#include "pf.h"     /* for PF_PrintError*/
#include "rm.h"     /* for RM_PrintError*/
#include "ix.h"     /* for IX_PrintError*/
#include "sm.h"
/* #include "ql.h"*/

#line 21 "y.tab.c"
#define VALUE_INTEGER 257
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
#define NULL_D 277
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
#define EOF 297
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    5,    5,    5,    5,    6,    7,    7,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    9,
    9,   23,   23,   10,   10,   10,   10,   11,   11,   12,
   12,   12,   12,    1,    1,    1,    1,    1,    1,   21,
   21,   13,   13,   14,   18,   18,   20,   20,   19,   19,
   22,   22,   17,   17,   16,   16,   15,   15,   15,    2,
    3,    4,
};
short yylen[] = {                                         2,
    0,    2,    1,    2,    2,    2,    2,    2,    3,    3,
    2,    2,    6,    3,    2,    5,    5,    6,    6,    6,
    6,    1,    3,    2,    4,    5,   10,    2,    2,    3,
    3,    4,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    1,    1,    1,    3,    1,    3,
    3,    1,    3,    3,    1,    3,    1,    1,    1,    1,
    1,    1,
};
short yydefred[] = {                                      0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    0,    0,    0,    0,    8,   12,    0,    0,
    0,    0,    0,    0,   60,   11,    0,    0,   61,    0,
    0,   45,    0,   52,    0,    0,   49,   15,    4,    5,
    6,    7,    9,    0,    0,   10,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   62,
    0,    0,   42,   51,   47,    0,   50,    0,    0,    0,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   13,    0,
   20,   21,   57,   58,   59,   55,    0,    0,    0,   34,
   35,   36,   37,   38,   39,    0,    0,   44,    0,   43,
    0,   48,    0,    0,   28,   29,    0,   23,   53,    0,
    0,    0,    0,   31,    0,   40,   30,   41,    0,    0,
   25,   56,   32,   26,    0,    0,    0,    0,    0,   27,
};
short yydgoto[] = {                                       2,
  107,   26,   33,   34,   12,   13,   14,   15,   16,   71,
   88,   77,   62,   63,   96,   97,   76,   35,   36,   66,
  127,   78,   72,
};
short yysindex[] = {                                   -280,
    0, -214, -236, -255, -252, -237, -247, -245, -192,  -33,
 -192,    0,   20,   24,   29,   30,    0,    0, -237, -192,
 -192, -237, -192, -192,    0,    0, -192, -192,    0, -194,
    0,    0,   46,    0, -189,   50,    0,    0,    0,    0,
    0,    0,    0,   55,   56,    0,    0,   57, -182, -184,
 -158, -158, -192, -157, -240, -158, -158,   63, -157,    0,
 -155,  -40,    0,    0,    0,  -38,    0, -173, -169, -241,
    0,   -6,   66,   67, -208,   65, -180, -219, -208, -157,
 -158, -157, -192,   73,   74, -142, -141, -159,    0, -240,
    0,    0,    0,    0,    0,    0,   21, -208, -157,    0,
    0,    0,    0,    0,    0, -191, -197,    0, -180,    0,
 -180,    0, -157, -158,    0,    0, -156,    0,    0, -208,
   75, -180, -154,    0,    0,    0,    0,    0,   33,   77,
    0,    0,    0,    0, -176, -192,   82, -158,   83,    0,
};
short yyrindex[] = {                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -41,    0,    0,    0,    0, -153,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   68,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   71,    0,
   72,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   78,   79,    0,    0,  -44,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   62,   -1,  -27,    0,    0,    0,    0,    0,   35,
    0,   -9,    0,   45,  -67,   36,    0,    0,   19,    0,
    0,   -3,    0,
};
#define YYTABLESIZE 291
short yytable[] = {                                      62,
    1,   61,   62,   81,   61,   83,   37,   30,   32,   38,
   19,  108,   20,   22,   58,   23,    1,   60,   44,   45,
   25,   47,   48,   61,   64,   49,   50,   70,   73,   74,
   17,   27,   18,   68,   89,   21,   28,   90,   24,  126,
  100,  101,  102,  103,  104,  105,   86,   87,   93,   94,
   67,   65,  132,   61,   69,    3,    4,    5,    6,   93,
  125,  119,   70,    7,  120,   29,    8,  106,   95,    9,
  109,   10,  111,  134,   24,   11,   54,   24,   39,   95,
   43,  112,   40,   46,  123,  124,  130,   41,   42,  122,
   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,
   31,   84,   75,  128,   79,   85,   91,   92,   98,   37,
  139,   99,  113,  114,  115,  116,  117,  135,  120,  136,
  131,  138,  133,  140,  118,  110,   16,   17,   46,   18,
   19,  129,    0,  121,  137,    0,   54,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   62,   62,
   62,   62,   62,   62,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,    0,   80,    0,   82,   62,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    1,    1,    1,    0,    0,    0,    0,    1,    0,
    0,    1,    0,    0,    1,    0,    1,    0,    0,    0,
    1,
};
short yycheck[] = {                                      41,
    0,   46,   44,   44,   46,   44,   10,    9,   42,   11,
  266,   79,  268,  266,   59,  268,  297,  258,   20,   21,
  258,   23,   24,   51,   52,   27,   28,   55,   56,   57,
  267,  279,  269,  274,   41,  291,  282,   44,  291,  107,
  260,  261,  262,  263,  264,  265,  288,  289,  257,  258,
   54,   53,  120,   81,  295,  270,  271,  272,  273,  257,
  258,   41,   90,  278,   44,  258,  281,  287,  277,  284,
   80,  286,   82,   41,   41,  290,   44,   44,   59,  277,
   19,   83,   59,   22,  276,  277,  114,   59,   59,   99,
  285,   46,  282,   44,   40,   40,   40,  280,  283,  258,
  258,  275,   40,  107,  260,  275,   41,   41,   44,  113,
  138,  292,   40,   40,  257,  257,  276,   41,   44,  296,
  277,   40,  277,   41,   90,   81,   59,   59,  282,   59,
   59,  113,   -1,   98,  136,   -1,   59,   59,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,  261,
  262,  263,  264,  265,  258,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  282,   -1,  283,   -1,  283,  287,   -1,  292,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,   -1,   -1,   -1,   -1,  278,   -1,
   -1,  281,   -1,   -1,  284,   -1,  286,   -1,   -1,   -1,
  290,
};
#define YYFINAL 2
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
"VALUE_INTEGER","VALUE_STRING","IDENTIFIER","EQ","NE","LT","LE","GT","GE",
"DATABASE","DATABASES","TABLE","TABLES","SHOW","CREATE","DROP","USE","PRIMARY",
"KEY","NOT","NULL_D","INSERT","INTO","VALUES","DELETE","FROM","WHERE","UPDATE",
"SET","SELECT","IS","INT","VARCHAR","DESC","INDEX","AND","DATE","FLOAT",
"FOREIGN","REFERENCES","EOF",
};
char *yyrule[] = {
"$accept : Program",
"Program :",
"Program : Program Stmt",
"Program : EOF",
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
"Field : ColName Type NOT NULL_D",
"Field : PRIMARY KEY '(' ColumnList ')'",
"Field : FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'",
"Type : INT VALUE_INTEGER",
"Type : VARCHAR VALUE_INTEGER",
"WhereClause : Column Op Expr",
"WhereClause : Column IS NULL_D",
"WhereClause : Column IS NOT NULL_D",
"WhereClause : WhereClause AND WhereClause",
"Op : EQ",
"Op : NE",
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
"Value : VALUE_INTEGER",
"Value : VALUE_STRING",
"Value : NULL_D",
"DbName : VALUE_STRING",
"TbName : VALUE_STRING",
"ColName : VALUE_STRING",
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
#line 371 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"

extern "C" {
    int yyparse(void);
    int yylex(void);
}
#line 319 "y.tab.c"
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
#line 52 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new Tree();
			    }
break;
case 2:
#line 56 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree->stmtList.push_back((Stmt*) yyvsp[0].tree);
			    }
break;
case 3:
#line 60 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = nullptr;
			    }
break;
case 4:
#line 66 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 5:
#line 70 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 6:
#line 74 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 7:
#line 78 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 8:
#line 84 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SysStmt();
                }
break;
case 9:
#line 89 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateDbStmt(yyvsp[0].identVal);
                }
break;
case 10:
#line 93 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DropDbStmt(yyvsp[0].identVal);
	            }
break;
case 11:
#line 97 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UseDbStmt(yyvsp[0].identVal);
	            }
break;
case 12:
#line 101 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ShowDbStmt();
	            }
break;
case 13:
#line 107 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateTbStmt(yyvsp[-3].identVal, &yyvsp[-1].tree->fieldList);
                }
break;
case 14:
#line 111 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropTbStmt(yyvsp[0].identVal);
                }
break;
case 15:
#line 115 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DescTbStmt(yyvsp[0].identVal);
	            }
break;
case 16:
#line 119 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new InsertTbStmt(yyvsp[-2].identVal, &yyvsp[0].tree->valueList);
	            }
break;
case 17:
#line 123 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DeleteTbStmt(yyvsp[-2].identVal, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 18:
#line 127 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UpdateTbStmt(yyvsp[-4].identVal, (SetClause*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 19:
#line 131 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new SelectTbStmt(&yyvsp[-4].tree->columnList, &yyvsp[-2].tree->tableList, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 20:
#line 137 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateIdxStmt(yyvsp[-3].identVal, yyvsp[-1].identVal);
                }
break;
case 21:
#line 141 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropIdxStmt(yyvsp[-3].identVal, yyvsp[-1].identVal);
                }
break;
case 22:
#line 147 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
                }
break;
case 23:
#line 152 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->fieldList.insert(yyval.tree->fieldList.end(), yyvsp[-2].tree->fieldList.begin(), yyvsp[-2].tree->fieldList.end());
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
		        }
break;
case 24:
#line 161 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NormalField((Identifier*) yyvsp[-1].identVal, (Type*) yyvsp[0].tree);
                }
break;
case 25:
#line 165 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NotNullField((Identifier*) yyvsp[-3].identVal, (Type*) yyvsp[-2].tree);
                }
break;
case 26:
#line 169 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new PrimaryField(&(yyvsp[-1].tree->columnList));
	            }
break;
case 27:
#line 173 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ForeignField(yyvsp[-6].identVal, yyvsp[-3].identVal, yyvsp[-1].identVal);
	            }
break;
case 28:
#line 179 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntType(yyvsp[0].intVal);
                }
break;
case 29:
#line 183 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new VarcharType(yyvsp[0].intVal);
	            }
break;
case 30:
#line 194 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NormalWhereClause((Column*) yyvsp[-2].tree, (Op*) yyvsp[-1].opVal, (Expr*) yyvsp[0].tree);
                }
break;
case 31:
#line 198 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((Column*) yyvsp[-2].tree, false);
			    }
break;
case 32:
#line 202 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((Column*) yyvsp[-3].tree, true);
			    }
break;
case 33:
#line 206 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new AndWhereClause((WhereClause*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
			    }
break;
case 34:
#line 212 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_EQ);
                }
break;
case 35:
#line 216 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_NE);
                }
break;
case 36:
#line 220 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_LT);
                }
break;
case 37:
#line 224 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_LE);
                }
break;
case 38:
#line 228 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_GT);
                }
break;
case 39:
#line 232 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_GE);
                }
break;
case 40:
#line 238 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new ValueExpr((Value*) yyvsp[0].tree);
                }
break;
case 41:
#line 242 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ColExpr((Column*) yyvsp[0].tree);
	            }
break;
case 42:
#line 248 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    std::list<SingleSetClause*> singleList;
                    singleList.push_back((SingleSetClause*) yyvsp[0].tree);
                    yyval.tree = new SetClause(&singleList);
                }
break;
case 43:
#line 254 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            std::list<SingleSetClause*>* beforeList = ((SetClause*) yyvsp[-2].tree)->getSetClauseList();
		            std::list<SingleSetClause*> singleList;
		            singleList.insert(singleList.end(), beforeList->begin(), beforeList->end());
		            singleList.push_back((SingleSetClause*) yyvsp[0].tree);
		            yyval.tree = new SetClause(&singleList);
		        }
break;
case 44:
#line 264 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SingleSetClause(yyvsp[-2].identVal, (Value*) yyvsp[0].tree);
                }
break;
case 45:
#line 269 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    /* Tree.columnList 是空的*/
                }
break;
case 46:
#line 273 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList = yyvsp[0].tree->columnList;
		        }
break;
case 47:
#line 280 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->tableList.push_back(yyvsp[0].identVal);
                }
break;
case 48:
#line 285 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->tableList.insert(yyval.tree->tableList.end(), yyvsp[-2].tree->tableList.begin(), yyvsp[-2].tree->tableList.end());
		            yyval.tree->tableList.push_back(yyvsp[0].identVal);
		        }
break;
case 49:
#line 293 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->columnList.push_back((Column*) yyvsp[0].tree);
                }
break;
case 50:
#line 298 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList.insert(yyval.tree->columnList.end(), yyvsp[-2].tree->columnList.begin(), yyvsp[-2].tree->columnList.end());
		            yyval.tree->columnList.push_back((Column*) yyvsp[0].tree);
		        }
break;
case 51:
#line 306 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[-2].identVal, yyvsp[0].identVal);
                }
break;
case 52:
#line 310 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[0].identVal);
                }
break;
case 53:
#line 316 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueLists.push_back(yyvsp[-1].tree->valueList);
                }
break;
case 54:
#line 321 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
                    yyval.tree->valueLists.insert(yyval.tree->valueLists.end(), yyvsp[-2].tree->valueLists.begin(), yyvsp[-2].tree->valueLists.end());
                    yyval.tree->valueLists.push_back(yyvsp[0].tree->valueList);
		        }
break;
case 55:
#line 329 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 56:
#line 334 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.insert(yyval.tree->valueList.end(), yyvsp[-2].tree->valueList.begin(), yyvsp[-2].tree->valueList.end());
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 57:
#line 342 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntValue(yyvsp[0].intVal);
                }
break;
case 58:
#line 346 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new StringValue(yyvsp[0].stringVal);
                }
break;
case 59:
#line 350 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new NullValue();
	            }
break;
case 60:
#line 356 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 61:
#line 361 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 62:
#line 366 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
#line 854 "y.tab.c"
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
