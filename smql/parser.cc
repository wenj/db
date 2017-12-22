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
#define VALUE_DOUBLE 259
#define VALUE_TIME 260
#define EQ 261
#define NE 262
#define LT 263
#define LE 264
#define GT 265
#define GE 266
#define DATABASE 267
#define DATABASES 268
#define TABLE 269
#define TABLES 270
#define SHOW 271
#define CREATE 272
#define DROP 273
#define USE 274
#define PRIMARY 275
#define KEY 276
#define NOT 277
#define NULL_D 278
#define INSERT 279
#define INTO 280
#define VALUES 281
#define DELETE 282
#define FROM 283
#define WHERE 284
#define UPDATE 285
#define SET 286
#define SELECT 287
#define IS 288
#define INT_D 289
#define VARCHAR 290
#define CHAR_D 291
#define FLOAT_D 292
#define DATE 293
#define DESC 294
#define INDEX 295
#define AND 296
#define FOREIGN 297
#define REFERENCES 298
#define EOF 299
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    5,    5,    5,    5,    6,    7,    7,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    9,
    9,   24,   24,   10,   10,   10,   10,   11,   11,   11,
   11,   11,   12,   12,   12,   12,    1,    1,    1,    1,
    1,    1,   22,   22,   13,   13,   14,   18,   18,   20,
   20,   19,   19,   21,   25,   23,   26,   26,   17,   17,
   16,   16,   15,   15,   15,   15,   15,    2,    3,    4,
};
short yylen[] = {                                         2,
    0,    2,    1,    2,    2,    2,    2,    2,    3,    3,
    2,    2,    6,    3,    2,    5,    5,    6,    6,    6,
    6,    1,    3,    2,    4,    5,   10,    4,    4,    4,
    1,    1,    3,    3,    4,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    1,    1,    1,
    3,    1,    3,    1,    1,    1,    1,    3,    3,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    0,    0,    0,    0,    8,   12,    0,    0,
    0,    0,    0,    0,   68,   54,   11,    0,    0,   69,
   55,    0,   70,   48,   56,    0,    0,   52,   15,    4,
    5,    6,    7,    9,    0,    0,   10,   14,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   45,    0,    0,   50,   53,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,    0,   57,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,
   31,    0,   13,    0,   20,   21,   63,   64,   66,   67,
   65,   61,    0,    0,    0,    0,   37,   38,   39,   40,
   41,   42,    0,    0,    0,   46,   47,    0,   51,    0,
    0,    0,    0,    0,    0,   23,   59,    0,    0,    0,
   58,    0,   34,   64,   43,   33,   44,    0,    0,    0,
    0,    0,   25,   62,   35,   26,    0,   28,   29,   30,
    0,    0,    0,    0,   27,
};
short yydgoto[] = {                                       2,
  114,   26,   31,   35,   12,   13,   14,   15,   16,   68,
   92,   76,   60,   61,  102,  103,   74,   36,   37,   63,
   27,  136,   77,   70,   78,   79,
};
short yysindex[] = {                                   -289,
    0, -211, -232, -258, -254, -244, -252, -229, -200,  -37,
 -200,    0,    5,    6,    7,   10,    0,    0, -244, -200,
 -200, -244, -200, -200,    0,    0,    0, -200, -200,    0,
    0, -216,    0,    0,    0, -208,   28,    0,    0,    0,
    0,    0,    0,    0,   38,   39,    0,    0,   40, -204,
 -202, -174, -200, -174, -246, -174, -174,   45, -167,  -41,
    0, -169,  -40,    0,    0, -179, -172,    0, -190,  -25,
   64,   66, -170,   65,    0, -186,    0,   69, -231, -167,
 -174, -170, -167, -200,   71,   76,   77,   78,   79,    0,
    0, -157,    0, -246,    0,    0,    0,    0,    0,    0,
    0,    0,  -17, -170, -167, -174,    0,    0,    0,    0,
    0,    0, -255, -164, -186,    0,    0, -186,    0, -174,
 -174, -136, -135, -134, -154,    0,    0, -170,   81, -186,
    0, -152,    0,    0,    0,    0,    0,   -1,   86,   87,
   88,   89,    0,    0,    0,    0, -166,    0,    0,    0,
 -200,   91, -174,   92,    0,
};
short yyrindex[] = {                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -149,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   80,  -46,   82,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   83,    0,    0,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   85,   90,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,
    0,  -38,    0,   55,  -75,   33,    0,    0,   18,    0,
   37,    0,   -8,    0,   -3,    0,
};
#define YYTABLESIZE 295
short yytable[] = {                                      69,
    1,   38,   81,   84,   34,   32,  117,   39,   19,    1,
   20,   33,   22,   25,   23,   93,   45,   46,   94,   48,
   49,  132,  133,  127,   50,   51,  128,   28,   66,  107,
  108,  109,  110,  111,  112,   17,   21,   18,  135,  146,
   24,  115,   54,   62,  118,   65,   69,   71,   72,   64,
   67,   24,  144,   29,   24,   44,  113,   30,   47,    3,
    4,    5,    6,   40,   41,   42,  130,    7,   43,   52,
    8,   54,   62,    9,   53,   10,   58,   55,   56,   57,
  119,   59,   11,   33,   73,   69,   97,   98,   99,  100,
   75,   82,   97,  134,   99,  100,   85,  131,   87,   88,
   89,   90,   91,   86,   95,  137,   96,  101,  104,  105,
  120,   38,  139,  101,  106,  121,  122,  123,  124,  125,
  140,  141,  142,  143,  128,  145,  147,  148,  149,  150,
  153,  151,  155,   49,  126,  116,  129,  138,   16,    0,
   17,   18,   19,   60,  154,    0,    0,  152,   36,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,   70,   70,   70,   70,   70,
   33,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   70,   80,   83,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,
    0,    0,    1,    0,    0,    1,    0,    1,    0,    0,
    0,    0,    0,    0,    1,
};
short yycheck[] = {                                      46,
    0,   10,   44,   44,   42,    9,   82,   11,  267,  299,
  269,  258,  267,  258,  269,   41,   20,   21,   44,   23,
   24,  277,  278,   41,   28,   29,   44,  280,  275,  261,
  262,  263,  264,  265,  266,  268,  295,  270,  114,   41,
  295,   80,   44,   52,   83,   54,   55,   56,   57,   53,
  297,   41,  128,  283,   44,   19,  288,  258,   22,  271,
  272,  273,  274,   59,   59,   59,  105,  279,   59,  286,
  282,   44,   81,  285,  283,  287,  281,   40,   40,   40,
   84,  284,  294,  258,   40,   94,  257,  258,  259,  260,
  258,  261,  257,  258,  259,  260,  276,  106,  289,  290,
  291,  292,  293,  276,   41,  114,   41,  278,   44,  296,
   40,  120,  121,  278,   46,   40,   40,   40,   40,  277,
  257,  257,  257,  278,   44,  278,   41,   41,   41,   41,
   40,  298,   41,  283,   94,   81,  104,  120,   59,   -1,
   59,   59,   59,   59,  153,   -1,   -1,  151,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  261,  262,  263,  264,  265,  266,
  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  288,  284,  284,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,  272,  273,  274,   -1,   -1,   -1,   -1,  279,
   -1,   -1,  282,   -1,   -1,  285,   -1,  287,   -1,   -1,
   -1,   -1,   -1,   -1,  294,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"VALUE_INTEGER","VALUE_STRING","VALUE_DOUBLE","VALUE_TIME","EQ","NE","LT","LE",
"GT","GE","DATABASE","DATABASES","TABLE","TABLES","SHOW","CREATE","DROP","USE",
"PRIMARY","KEY","NOT","NULL_D","INSERT","INTO","VALUES","DELETE","FROM","WHERE",
"UPDATE","SET","SELECT","IS","INT_D","VARCHAR","CHAR_D","FLOAT_D","DATE","DESC",
"INDEX","AND","FOREIGN","REFERENCES","EOF",
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
"Type : INT_D '(' VALUE_INTEGER ')'",
"Type : VARCHAR '(' VALUE_INTEGER ')'",
"Type : CHAR_D '(' VALUE_INTEGER ')'",
"Type : DATE",
"Type : FLOAT_D",
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
"Value : VALUE_DOUBLE",
"Value : VALUE_TIME",
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
#line 411 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"

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
#line 380 "y.tab.c"
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
#line 57 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new Tree();
			    }
break;
case 2:
#line 61 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new Tree();
			        yyval.tree->stmtList.insert(yyval.tree->stmtList.end(), yyvsp[-1].tree->stmtList.begin(), yyvsp[0].tree->stmtList.end());
			        yyval.tree->stmtList.push_back((Stmt*) yyvsp[0].tree);
			    }
break;
case 3:
#line 67 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = nullptr;
			    }
break;
case 4:
#line 73 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 5:
#line 77 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 6:
#line 81 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 7:
#line 85 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = yyvsp[-1].tree;
                }
break;
case 8:
#line 91 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SysStmt();
                }
break;
case 9:
#line 96 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateDbStmt((Database*) yyvsp[0].tree);
                }
break;
case 10:
#line 100 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DropDbStmt((Database*) yyvsp[0].tree);
	            }
break;
case 11:
#line 104 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UseDbStmt((Database*) yyvsp[0].tree);
	            }
break;
case 12:
#line 108 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ShowDbStmt();
	            }
break;
case 13:
#line 114 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateTbStmt((Table*) yyvsp[-3].tree, &yyvsp[-1].tree->fieldList);
                }
break;
case 14:
#line 118 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropTbStmt((Table*) yyvsp[0].tree);
                }
break;
case 15:
#line 122 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DescTbStmt((Table*) yyvsp[0].tree);
	            }
break;
case 16:
#line 126 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new InsertTbStmt((Table*) yyvsp[-2].tree, &yyvsp[0].tree->valueList);
	            }
break;
case 17:
#line 130 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DeleteTbStmt((Table*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 18:
#line 134 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new UpdateTbStmt((Table*) yyvsp[-4].tree, (SetClause*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 19:
#line 138 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new SelectTbStmt(&yyvsp[-4].tree->columnList, &yyvsp[-2].tree->tableList, (WhereClause*) yyvsp[0].tree);
	            }
break;
case 20:
#line 144 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new CreateIdxStmt((Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
                }
break;
case 21:
#line 148 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new DropIdxStmt((Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
                }
break;
case 22:
#line 154 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
                }
break;
case 23:
#line 159 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->fieldList.insert(yyval.tree->fieldList.end(), yyvsp[-2].tree->fieldList.begin(), yyvsp[-2].tree->fieldList.end());
                    yyval.tree->fieldList.push_back((Field*) yyvsp[0].tree);
		        }
break;
case 24:
#line 167 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NormalField((Column*) yyvsp[-1].tree, (Type*) yyvsp[0].tree);
                }
break;
case 25:
#line 171 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NotNullField((Column*) yyvsp[-3].tree, (Type*) yyvsp[-2].tree);
                }
break;
case 26:
#line 175 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new PrimaryField(&yyvsp[-1].tree->columnList);
	            }
break;
case 27:
#line 179 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ForeignField((Column*) yyvsp[-6].tree, (Table*) yyvsp[-3].tree, (Column*) yyvsp[-1].tree);
	            }
break;
case 28:
#line 186 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntType(yyvsp[-1].intVal);
                }
break;
case 29:
#line 190 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new VarcharType(yyvsp[-1].intVal);
	            }
break;
case 30:
#line 194 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new CharType(yyvsp[-1].intVal);
	            }
break;
case 31:
#line 198 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new TimeType();
	            }
break;
case 32:
#line 202 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DoubleType();
	            }
break;
case 33:
#line 208 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new NormalWhereClause((TabledColumn*) yyvsp[-2].tree, (Op*) yyvsp[-1].opVal, (Expr*) yyvsp[0].tree);
                }
break;
case 34:
#line 212 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((TabledColumn*) yyvsp[-2].tree, false);
			    }
break;
case 35:
#line 216 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new IsNullWhereClause((TabledColumn*) yyvsp[-3].tree, true);
			    }
break;
case 36:
#line 220 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
			        yyval.tree = new AndWhereClause((WhereClause*) yyvsp[-2].tree, (WhereClause*) yyvsp[0].tree);
			    }
break;
case 37:
#line 226 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_EQ);
                }
break;
case 38:
#line 230 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_NE);
                }
break;
case 39:
#line 234 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_LT);
                }
break;
case 40:
#line 238 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_LE);
                }
break;
case 41:
#line 242 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_GT);
                }
break;
case 42:
#line 246 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.opVal = new Op(Tree::OP_GE);
                }
break;
case 43:
#line 252 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new ValueExpr((Value*) yyvsp[0].tree);
                }
break;
case 44:
#line 256 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new ColExpr((Column*) yyvsp[0].tree);
	            }
break;
case 45:
#line 262 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    std::list<SingleSetClause*> singleList;
                    singleList.push_back((SingleSetClause*) yyvsp[0].tree);
                    yyval.tree = new SetClause(&singleList);
                }
break;
case 46:
#line 268 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            std::list<SingleSetClause*>* beforeList = ((SetClause*) yyvsp[-2].tree)->getSetClauseList();
		            std::list<SingleSetClause*> singleList;
		            singleList.insert(singleList.end(), beforeList->begin(), beforeList->end());
		            singleList.push_back((SingleSetClause*) yyvsp[0].tree);
		            yyval.tree = new SetClause(&singleList);
		        }
break;
case 47:
#line 278 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new SingleSetClause((Column*) yyvsp[-2].tree, (Value*) yyvsp[0].tree);
                }
break;
case 48:
#line 283 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    /* Tree.columnList 是空的*/
                }
break;
case 49:
#line 287 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList = yyvsp[0].tree->columnList;
		        }
break;
case 50:
#line 294 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->tableList.push_back((Table*) yyvsp[0].tree);
                }
break;
case 51:
#line 299 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->tableList.insert(yyval.tree->tableList.end(), yyvsp[-2].tree->tableList.begin(), yyvsp[-2].tree->tableList.end());
		            yyval.tree->tableList.push_back((Table*) yyvsp[0].tree);
		        }
break;
case 52:
#line 307 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->columnList.push_back((Column*) yyvsp[0].tree);
                }
break;
case 53:
#line 312 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
		            yyval.tree->columnList.insert(yyval.tree->columnList.end(), yyvsp[-2].tree->columnList.begin(), yyvsp[-2].tree->columnList.end());
		            yyval.tree->columnList.push_back((Column*) yyvsp[0].tree);
		        }
break;
case 54:
#line 320 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Database(yyvsp[0].identVal);
                }
break;
case 55:
#line 325 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Table(yyvsp[0].identVal);
                }
break;
case 56:
#line 331 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Column(yyvsp[0].identVal);
                }
break;
case 57:
#line 338 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new TabledColumn((Column*) yyvsp[0].tree);
                }
break;
case 58:
#line 342 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new TabledColumn((Table*) yyvsp[-2].tree, (Column*) yyvsp[0].tree);
                }
break;
case 59:
#line 348 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueLists.push_back(yyvsp[-1].tree->valueList);
                }
break;
case 60:
#line 353 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
		            yyval.tree = new Tree();
                    yyval.tree->valueLists.insert(yyval.tree->valueLists.end(), yyvsp[-2].tree->valueLists.begin(), yyvsp[-2].tree->valueLists.end());
                    yyval.tree->valueLists.push_back(yyvsp[0].tree->valueList);
		        }
break;
case 61:
#line 361 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 62:
#line 366 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new Tree();
                    yyval.tree->valueList.insert(yyval.tree->valueList.end(), yyvsp[-2].tree->valueList.begin(), yyvsp[-2].tree->valueList.end());
                    yyval.tree->valueList.push_back((Value*) yyvsp[0].tree);
                }
break;
case 63:
#line 374 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new IntValue(yyvsp[0].intVal);
                }
break;
case 64:
#line 378 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.tree = new StringValue(yyvsp[0].stringVal);
                }
break;
case 65:
#line 382 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new NullValue();
	            }
break;
case 66:
#line 386 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new DoubleValue(yyvsp[0].doubleVal);
	            }
break;
case 67:
#line 390 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
	                yyval.tree = new TimeValue(yyvsp[0].timeVal);
	            }
break;
case 68:
#line 396 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 69:
#line 401 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
case 70:
#line 406 "C:/Users/lenovo/Documents/GitHub/db/smql/parser.y"
{
                    yyval.identVal = new Identifier(yyvsp[0].stringVal);
                }
break;
#line 965 "y.tab.c"
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
