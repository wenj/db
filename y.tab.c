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
#define EQ 257
#define NE 258
#define LT 259
#define LE 260
#define GT 261
#define GE 262
#define DATABASE 263
#define DATABASES 264
#define TABLE 265
#define TABLES 266
#define SHOW 267
#define CREATE 268
#define DROP 269
#define USE 270
#define PRIMARY 271
#define KEY 272
#define NOT 273
#define NULL 274
#define INSERT 275
#define INTO 276
#define VALUES 277
#define DELETE 278
#define FROM 279
#define WHERE 280
#define UPDATE 281
#define SET 282
#define SELECT 283
#define IS 284
#define INT 285
#define VARCHAR 286
#define DESC 287
#define INDEX 288
#define AND 289
#define DATE 290
#define FLOAT 291
#define FOREIGN 292
#define REFERENCES 293
#define VALUE_INT 294
#define VALUE_STRING 295
#define NQ 296
#define IDENTIFIER 297
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    1,    2,    3,    3,    3,
    3,    4,    4,    4,    4,    4,    4,    4,    5,    5,
    8,    8,   15,   15,   15,   15,   16,   16,   16,   16,
    9,    9,   18,   18,   19,   19,   19,   10,   10,   10,
   20,   21,   21,   21,   21,   21,   21,   22,   22,   11,
   11,   12,   12,   23,   23,   13,   13,   17,   17,    6,
    7,   14,
};
short yylen[] = {                                         2,
    0,    2,    2,    2,    2,    2,    2,    3,    3,    2,
    2,    6,    3,    2,    5,    5,    6,    6,    6,    6,
    1,    3,    2,    4,    5,   10,    2,    2,    1,    1,
    3,    3,    1,    3,    1,    1,    1,    3,    4,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    5,    1,    1,    1,    2,    1,    3,    1,    3,    1,
    1,    1,
};
short yydefred[] = {                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    0,    0,    0,    0,    7,   11,    0,    0,    0,
    0,    0,    0,   60,   10,    0,    0,   61,    0,   52,
    0,    0,   54,    0,   14,    3,    4,    5,    6,    8,
    0,    0,    9,   13,    0,    0,    0,    0,    0,    0,
   55,    0,    0,    0,    0,    0,   62,    0,    0,   41,
   56,    0,    0,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   12,    0,    0,    0,   29,   30,    0,   19,   20,   37,
   35,   36,    0,   33,    0,    0,   42,   44,   45,   46,
   47,    0,   43,    0,    0,    0,   50,    0,   57,    0,
    0,   22,   27,   28,    0,   31,    0,    0,    0,    0,
   48,   49,   38,    0,   58,    0,    0,   24,   34,   39,
   51,   25,    0,    0,   59,    0,    0,    0,    0,   26,
};
short yydgoto[] = {                                       1,
   11,   12,   13,   14,   15,   25,   31,   65,   71,   72,
   58,   32,   62,   66,   67,   87,  126,   93,   94,   73,
  104,  123,   34,
};
short yysindex[] = {                                      0,
 -192, -215, -238, -217, -287, -261, -243, -256,  -42, -256,
    0,   -3,    2,    8,   11,    0,    0, -287, -256, -256,
 -287, -256, -256,    0,    0, -256, -256,    0, -209,    0,
   33, -197,    0, -256,    0,    0,    0,    0,    0,    0,
   44,   45,    0,    0,   47, -189, -190, -205, -205, -256,
    0, -264, -205, -205,   53, -256,    0,  -43, -163,    0,
    0,  -41, -176, -175,  -33, -227,    0,   57,   58, -252,
   60, -188, -222, -256, -205, -252, -256, -256,   62,   65,
    0, -264, -187, -185,    0,    0, -167,    0,    0,    0,
    0,    0,  -15,    0, -252, -256,    0,    0,    0,    0,
    0, -162,    0, -242, -188, -147,    0, -188,    0, -205,
 -205,    0,    0,    0, -161,    0, -252,   68, -188, -160,
    0,    0,    0, -252,    0,   16,   74,    0,    0,    0,
    0,    0, -205, -177,    0, -256,   77, -205,   78,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -159,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   59,   63,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   64,    0,    0,   66,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   67,   69,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,    0,    0,   48,   -6,    0,    0,  -65,
    0,    0,    0,  -30,   39,    0,    0,   29,  -70,   -4,
    0,    0,    0,
};
#define YYTABLESIZE 255
short yytable[] = {                                      30,
   75,   29,   78,   35,   33,  107,   63,   81,  105,   24,
   82,  108,   41,   42,   26,   44,   45,   59,   60,   46,
   47,   90,   68,   69,   18,  116,   19,   64,  117,   51,
  119,   90,   57,  121,   97,   27,   98,   99,  100,  101,
   28,   91,   92,   61,  106,   21,  129,   22,   16,   20,
   17,   91,   92,  131,   28,   36,  132,   83,   84,  133,
   37,  102,   85,   86,   23,   40,   38,   23,   43,   39,
   23,  109,   48,  103,    2,    3,    4,    5,   49,  125,
  127,   50,    6,   52,   53,    7,   54,   55,    8,   56,
    9,   57,   70,   76,   10,   79,   80,   88,   89,  122,
   96,  110,  135,   95,  111,  115,  113,  139,  114,  124,
  120,  117,  128,  130,  134,  136,  138,   15,  140,   53,
  112,   16,   17,  118,   18,   32,    0,   40,    0,  137,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,    0,   77,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   28,
};
short yycheck[] = {                                      42,
   44,    8,   44,   10,    9,   76,  271,   41,   74,  297,
   44,   77,   19,   20,  276,   22,   23,   48,   49,   26,
   27,  274,   53,   54,  263,   41,  265,  292,   44,   34,
   96,  274,  297,  104,  257,  279,  259,  260,  261,  262,
  297,  294,  295,   50,   75,  263,  117,  265,  264,  288,
  266,  294,  295,  124,  297,   59,   41,  285,  286,   44,
   59,  284,  290,  291,   41,   18,   59,   44,   21,   59,
  288,   78,  282,  296,  267,  268,  269,  270,   46,  110,
  111,  279,  275,   40,   40,  278,   40,  277,  281,  280,
  283,  297,   40,  257,  287,  272,  272,   41,   41,  104,
  289,   40,  133,   44,   40,  273,  294,  138,  294,  257,
  273,   44,  274,  274,   41,  293,   40,   59,   41,  279,
   82,   59,   59,   95,   59,   59,   -1,   59,   -1,  136,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  280,   -1,  280,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  297,
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EQ","NE",
"LT","LE","GT","GE","DATABASE","DATABASES","TABLE","TABLES","SHOW","CREATE",
"DROP","USE","PRIMARY","KEY","NOT","NULL","INSERT","INTO","VALUES","DELETE",
"FROM","WHERE","UPDATE","SET","SELECT","IS","INT","VARCHAR","DESC","INDEX",
"AND","DATE","FLOAT","FOREIGN","REFERENCES","VALUE_INT","VALUE_STRING","NQ",
"IDENTIFIER",
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
"ValueLists : '(' ValueList ')'",
"ValueLists : ValueLists ',' ValueList",
"ValueList : Value",
"ValueList : ValueList ',' Value",
"Value : VALUE_INT",
"Value : VALUE_STRING",
"Value : NULL",
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
"Expr : Col",
"SetClause : ColName EQ Value",
"SetClause : SetClause ',' ColName EQ Value",
"Selector : '*'",
"Selector : ColList",
"ColList : Col",
"ColList : ColList Col",
"TableList : TbName",
"TableList : TableList ',' TbName",
"ColumnList : ColName",
"ColumnList : ColumnList ',' ColName",
"DbName : IDENTIFIER",
"TbName : IDENTIFIER",
"ColName : IDENTIFIER",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
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
#line 19 "smql/parser.y"
{
			}
break;
case 2:
#line 22 "smql/parser.y"
{
			}
break;
#line 448 "y.tab.c"
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
