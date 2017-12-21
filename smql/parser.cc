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
#include <iostream>

#line 22 "y.tab.c"
#define VALUE_INTEGER 257
#define VALUE_STRING 258
#define EQ 259
#define NE 260
#define LT 261
#define LE 262
#define GT 263
#define GE 264
#define DATABASE 265
#define DATABASES 266
#define TABLE 267
#define TABLES 268
#define SHOW 269
#define CREATE 270
#define DROP 271
#define USE 272
#define PRIMARY 273
#define KEY 274
#define NOT 275
#define NULL_D 276
#define INSERT 277
#define INTO 278
#define VALUES 279
#define DELETE 280
#define FROM 281
#define WHERE 282
#define UPDATE 283
#define SET 284
#define SELECT 285
#define IS 286
#define INT_D 287
#define VARCHAR 288
#define DESC 289
#define INDEX 290
#define AND 291
#define DATE 292
#define FLOAT_D 293
#define FOREIGN 294
#define REFERENCES 295
#define EOF 296
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    5,    5,    5,    5,    6,    7,    7,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    9,
    9,   24,   24,   10,   10,   10,   10,   11,   11,   12,
   12,   12,   12,    1,    1,    1,    1,    1,    1,   22,
   22,   13,   13,   14,   18,   18,   20,   20,   19,   19,
   21,   25,   23,   26,   26,   17,   17,   16,   16,   15,
   15,   15,    2,    3,    4,
};
short yylen[] = {                                         2,
    0,    2,    1,    2,    2,    2,    2,    2,    3,    3,
    2,    2,    6,    3,    2,    5,    5,    6,    6,    6,
    6,    1,    3,    2,    4,    5,   10,    2,    2,    3,
    3,    4,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    1,    1,    1,    3,    1,    3,
    1,    1,    1,    1,    3,    3,    3,    1,    3,    1,
    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    0,    0,    0,    0,    8,   12,    0,    0,
    0,    0,    0,    0,   63,   51,   11,    0,    0,   64,
   52,    0,   65,   45,   53,    0,    0,   49,   15,    4,
    5,    6,    7,    9,    0,    0,   10,   14,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,   47,   50,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,    0,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,
    0,   20,   21,   60,   61,   62,   58,    0,    0,    0,
    0,   34,   35,   36,   37,   38,   39,    0,    0,    0,
   43,   44,    0,   48,    0,    0,   28,   29,    0,   23,
   56,    0,    0,    0,   55,    0,   31,   61,   40,   30,
   41,    0,    0,   25,   59,   32,   26,    0,    0,    0,
    0,    0,   27,
};
short yydgoto[] = {                                       2,
  109,   26,   31,   35,   12,   13,   14,   15,   16,   68,
   89,   76,   60,   61,   97,   98,   74,   36,   37,   63,
   27,  130,   77,   70,   78,   79,
};
short yysindex[] = {                                   -287,
    0, -214, -227, -255, -231, -239, -233, -213, -188,  -37,
 -188,    0,   13,   17,   19,   25,    0,    0, -239, -188,
 -188, -239, -188, -188,    0,    0,    0, -188, -188,    0,
    0, -204,    0,    0,    0, -195,   43,    0,    0,    0,
    0,    0,    0,    0,   48,   49,    0,    0,   50, -187,
 -191, -164, -188, -164, -251, -164, -164,   55, -162,  -41,
    0, -161,  -40,    0,    0, -177, -175,    0, -273,   -4,
   59,   61, -234,   60,    0, -186,    0,   57, -232, -162,
 -164, -234, -162, -188,   66,   69, -147, -146, -163,    0,
 -251,    0,    0,    0,    0,    0,    0,   21, -234, -162,
 -164,    0,    0,    0,    0,    0,    0, -223, -197, -186,
    0,    0, -186,    0, -164, -164,    0,    0, -160,    0,
    0, -234,   70, -186,    0, -159,    0,    0,    0,    0,
    0,   23,   72,    0,    0,    0,    0, -180, -188,   78,
 -164,   79,    0,
};
short yyrindex[] = {                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -158,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   62,  -46,   65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   67,
    0,    0,   68,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   71,   73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
    0,  -67,    0,   41,  -71,   26,    0,    0,   14,    0,
   63,    0,   -8,    0,   -3,    0,
};
#define YYTABLESIZE 290
short yytable[] = {                                      64,
    1,   38,   81,   84,   34,   32,   33,   39,    1,   19,
  112,   20,  110,   87,   88,  113,   45,   46,   25,   48,
   49,   66,   94,   95,   50,   51,  102,  103,  104,  105,
  106,  107,  124,   22,   21,   23,   90,  129,   17,   91,
   18,   96,   67,   62,   28,   65,   69,   71,   72,   64,
  135,  126,  127,  108,    3,    4,    5,    6,   24,   94,
  128,  121,    7,  137,  122,    8,   54,   29,    9,   30,
   10,   40,   62,   24,   11,   41,   24,   42,   96,   52,
  114,   44,   69,   43,   47,   53,   54,   55,   56,   57,
   59,   58,  125,   33,   73,   75,   85,   82,   86,   92,
  131,   93,  101,   99,  100,  115,   38,  133,  116,  117,
  118,  119,  138,  122,  139,  134,  136,  141,  120,  143,
   16,  111,   46,   17,  123,   18,   19,    0,  132,   57,
    0,   33,  142,    0,    0,  140,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,   65,   65,   65,   65,   65,    0,    0,
   33,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   65,
   80,   83,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    1,    1,    1,    0,    0,    0,    0,    1,    0,    0,
    1,    0,    0,    1,    0,    1,    0,    0,    0,    1,
};
short yycheck[] = {                                      46,
    0,   10,   44,   44,   42,    9,  258,   11,  296,  265,
   82,  267,   80,  287,  288,   83,   20,   21,  258,   23,
   24,  273,  257,  258,   28,   29,  259,  260,  261,  262,
  263,  264,  100,  265,  290,  267,   41,  109,  266,   44,
  268,  276,  294,   52,  278,   54,   55,   56,   57,   53,
  122,  275,  276,  286,  269,  270,  271,  272,  290,  257,
  258,   41,  277,   41,   44,  280,   44,  281,  283,  258,
  285,   59,   81,   41,  289,   59,   44,   59,  276,  284,
   84,   19,   91,   59,   22,  281,   44,   40,   40,   40,
  282,  279,  101,  258,   40,  258,  274,  259,  274,   41,
  109,   41,   46,   44,  291,   40,  115,  116,   40,  257,
  257,  275,   41,   44,  295,  276,  276,   40,   91,   41,
   59,   81,  281,   59,   99,   59,   59,   -1,  115,   59,
   -1,   59,  141,   -1,   -1,  139,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  259,  260,  261,  262,  263,  264,   -1,   -1,
  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  282,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  271,  272,   -1,   -1,   -1,   -1,  277,   -1,   -1,
  280,   -1,   -1,  283,   -1,  285,   -1,   -1,   -1,  289,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"VALUE_INTEGER","VALUE_STRING","EQ","NE","LT","LE","GT","GE","DATABASE",
"DATABASES","TABLE","TABLES","SHOW","CREATE","DROP","USE","PRIMARY","KEY","NOT",
"NULL_D","INSERT","INTO","VALUES","DELETE","FROM","WHERE","UPDATE","SET",
"SELECT","IS","INT_D","VARCHAR","DESC","INDEX","AND","DATE","FLOAT_D","FOREIGN",
"REFERENCES","EOF",
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
"DbStmt : CREATE DATABASE Database",
"DbStmt : DROP DATABASE Database",
"DbStmt : USE Database",
"DbStmt : SHOW TABLES",
"TbStmt : CREATE TABLE Table '(' FieldList ')'",
"TbStmt : DROP TABLE Table",
"TbStmt : DESC Table",
"TbStmt : INSERT INTO Table VALUES ValueLists",
"TbStmt : DELETE FROM Table WHERE WhereClause",
"TbStmt : UPDATE Table SET SetClause WHERE WhereClause",
"TbStmt : SELECT Selector FROM TableList WHERE WhereClause",
"IdxStmt : CREATE INDEX Table '(' Column ')'",
"IdxStmt : DROP INDEX Table '(' Column ')'",
"FieldList : Field",
"FieldList : FieldList ',' Field",
"Field : Column Type",
"Field : Column Type NOT NULL_D",
"Field : PRIMARY KEY '(' ColumnList ')'",
"Field : FOREIGN KEY '(' Column ')' REFERENCES Table '(' Column ')'",
"Type : INT_D VALUE_INTEGER",
"Type : VARCHAR VALUE_INTEGER",
"WhereClause : TabledColumn Op Expr",
"WhereClause : TabledColumn IS NULL_D",
"WhereClause : TabledColumn IS NOT NULL_D",
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
"SingleSetClause : Column EQ Value",
"Selector : '*'",
"Selector : ColumnList",
"TableList : Table",
"TableList : TableList ',' Table",
"ColumnList : Column",
"ColumnList : ColumnList ',' Column",
"Database : DbName",
"Table : TbName",
"Column : ColName",
"TabledColumn : Column",
"TabledColumn : Table '.' Column",
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
#line 389 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"

extern "C" {
    int yyparse(void);
    int yylex(void);
}

// 以下是抄来的

void Parse()
{
    static const char* PROMPT = "\nDATABASE << ";

    /* Do forever */
    while (true) {

        /* Print a prompt */
        cout << PROMPT;

        /* Get the prompt to actually show up on the screen */
        cout.flush();

        int i = yyparse();

        /* If a query was successfully read, interpret it */
        if(i == 0 && yyval.tree != nullptr) {
            yyval.tree->print();
        }

        cout << "处理完了" << endl;
    }
}

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
#line 367 "y.tab.c"
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
#line 53 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new Tree();
			    }
break;
case 2:
#line 57 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree->stmtList.push_back((Stmt*) yyvsp[0].tree);
			    }
break;
case 3:
#line 61 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = nullptr;
			    }
break;
case 4:
#line 67 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 5:
#line 71 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 6:
#line 75 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 7:
#line 79 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 8:
#line 85 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SysStmt();
                }
break;
case 9:
#line 90 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateDbStmt((Database*) yyvsp[0].tree);
                }
break;
case 10:
#line 94 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DropDbStmt((Database*) yyvsp[0].tree);
	            }
break;
case 11:
#line 98 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UseDbStmt((Database*) yyvsp[0].tree);
	            }
break;
case 12:
#line 102 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ShowDbStmt();
	            }
break;
case 13:
#line 108 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateTbStmt((Table*) yyvsp[-3].tree, &yyvsp[-1].tree->fieldList);
                }
break;
case 14:
#line 112 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropTbStmt((Table*) yyvsp[0].tree);
                }
break;
case 15:
#line 116 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DescTbStmt((Table*) yyvsp[0].tree);
	            }
break;
case 16:
#line 120 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new InsertTbStmt((Table*) yyvsp[-2].tree, &yyvsp[0].tree->valueList);
	            }
break;
case 17:
#line 124 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DeleteTbStmt((Table*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 18:
#line 128 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UpdateTbStmt((Table*) yyvsp[-4].tree, (SetClause*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 19:
#line 132 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new SelectTbStmt(&yyvsp[-4].tree->columnList, &yyvsp[-2].tree->tableList, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 20:
#line 138 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateIdxStmt((Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
                }
break;
case 21:
#line 142 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropIdxStmt((Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
                }
break;
case 22:
#line 148 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
                }
break;
case 23:
#line 153 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->fieldList.insert(yyval.tree->fieldList.end(), yyvsp[-2].tree->fieldList.begin(), yyvsp[-2].tree->fieldList.end());
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
		        }
break;
case 24:
#line 161 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NormalField((Column*) yyvsp[-1].tree, (Type*) yyvsp[0].tree);
                }
break;
case 25:
#line 165 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NotNullField((Column*) yyvsp[-3].tree, (Type*) yyvsp[-2].tree);
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
	                yyval.tree = new ForeignField((Column*) yyvsp[-6].tree, (Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
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
                    yyval.tree = new NormalWhereClause((TabledColumn*) yyvsp[-2].tree, (Op*) yyvsp[-1].opVal, (Expr*) yyvsp[0].tree);
                }
break;
case 31:
#line 198 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((TabledColumn*) yyvsp[-2].tree, false);
			    }
break;
case 32:
#line 202 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((TabledColumn*) yyvsp[-3].tree, true);
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
                    yyval.tree = new SingleSetClause((Column*) yyvsp[-2].tree, (Value*) yyvsp[0].tree);
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
                    yyval.tree->tableList.push_back((Table*) yyvsp[0].tree);
                }
break;
case 48:
#line 285 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->tableList.insert(yyval.tree->tableList.end(), yyvsp[-2].tree->tableList.begin(), yyvsp[-2].tree->tableList.end());
		            yyval.tree->tableList.push_back((Table*) yyvsp[0].tree);
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
                    yyval.tree = new Database(yyvsp[0].identVal);
                }
break;
case 52:
#line 311 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Table(yyvsp[0].identVal);
                }
break;
case 53:
#line 317 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[0].identVal);
                }
break;
case 54:
#line 324 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new TabledColumn((Column*) yyvsp[0].tree);
                }
break;
case 55:
#line 328 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new TabledColumn((Table*) yyvsp[-2].tree, (Column*) yyvsp[0].tree);
                }
break;
case 56:
#line 334 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueLists.push_back(yyvsp[-1].tree->valueList);
                }
break;
case 57:
#line 339 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
                    yyval.tree->valueLists.insert(yyval.tree->valueLists.end(), yyvsp[-2].tree->valueLists.begin(), yyvsp[-2].tree->valueLists.end());
                    yyval.tree->valueLists.push_back(yyvsp[0].tree->valueList);
		        }
break;
case 58:
#line 347 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 59:
#line 352 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.insert(yyval.tree->valueList.end(), yyvsp[-2].tree->valueList.begin(), yyvsp[-2].tree->valueList.end());
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 60:
#line 360 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntValue(yyvsp[0].intVal);
                }
break;
case 61:
#line 364 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new StringValue(yyvsp[0].stringVal);
                }
break;
case 62:
#line 368 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new NullValue();
	            }
break;
case 63:
#line 374 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 64:
#line 379 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 65:
#line 384 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
#line 920 "y.tab.c"
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
