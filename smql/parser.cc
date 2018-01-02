/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:339  */

// #include "YYSTYPE.h"
#include "Tree.h"
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
#include "sm.h"
// #include "ql.h"
#include <iostream>


#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VALUE_INTEGER = 258,
    VALUE_STRING = 259,
    VALUE_DOUBLE = 260,
    VALUE_TIME = 261,
    EQ = 262,
    NE = 263,
    LT = 264,
    LE = 265,
    GT = 266,
    GE = 267,
    DATABASE = 268,
    DATABASES = 269,
    TABLE = 270,
    TABLES = 271,
    SHOW = 272,
    CREATE = 273,
    DROP = 274,
    USE = 275,
    PRIMARY = 276,
    KEY = 277,
    NOT = 278,
    NULL_D = 279,
    INSERT = 280,
    INTO = 281,
    VALUES = 282,
    DELETE = 283,
    FROM = 284,
    WHERE = 285,
    UPDATE = 286,
    SET = 287,
    SELECT = 288,
    IS = 289,
    INT_D = 290,
    VARCHAR = 291,
    CHAR_D = 292,
    FLOAT_D = 293,
    DATE = 294,
    DESC = 295,
    INDEX = 296,
    AND = 297,
    FOREIGN = 298,
    REFERENCES = 299
  };
#endif
/* Tokens.  */
#define VALUE_INTEGER 258
#define VALUE_STRING 259
#define VALUE_DOUBLE 260
#define VALUE_TIME 261
#define EQ 262
#define NE 263
#define LT 264
#define LE 265
#define GT 266
#define GE 267
#define DATABASE 268
#define DATABASES 269
#define TABLE 270
#define TABLES 271
#define SHOW 272
#define CREATE 273
#define DROP 274
#define USE 275
#define PRIMARY 276
#define KEY 277
#define NOT 278
#define NULL_D 279
#define INSERT 280
#define INTO 281
#define VALUES 282
#define DELETE 283
#define FROM 284
#define WHERE 285
#define UPDATE 286
#define SET 287
#define SELECT 288
#define IS 289
#define INT_D 290
#define VARCHAR 291
#define CHAR_D 292
#define FLOAT_D 293
#define DATE 294
#define DESC 295
#define INDEX 296
#define AND 297
#define FOREIGN 298
#define REFERENCES 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:355  */

    int intVal;
    char *stringVal;
    double doubleVal;
    struct tm timeVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;

#line 216 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,    49,     2,    48,     2,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    59,    67,    71,    75,    79,    85,    90,
      94,    98,   102,   108,   112,   116,   120,   124,   128,   132,
     138,   142,   148,   153,   161,   165,   169,   173,   180,   184,
     188,   192,   196,   202,   206,   210,   214,   220,   224,   228,
     232,   236,   240,   246,   250,   256,   262,   272,   277,   281,
     288,   293,   301,   306,   314,   319,   325,   332,   336,   342,
     347,   355,   360,   368,   372,   376,   380,   384,   390,   395,
     400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VALUE_INTEGER", "VALUE_STRING",
  "VALUE_DOUBLE", "VALUE_TIME", "EQ", "NE", "LT", "LE", "GT", "GE",
  "DATABASE", "DATABASES", "TABLE", "TABLES", "SHOW", "CREATE", "DROP",
  "USE", "PRIMARY", "KEY", "NOT", "NULL_D", "INSERT", "INTO", "VALUES",
  "DELETE", "FROM", "WHERE", "UPDATE", "SET", "SELECT", "IS", "INT_D",
  "VARCHAR", "CHAR_D", "FLOAT_D", "DATE", "DESC", "INDEX", "AND",
  "FOREIGN", "REFERENCES", "';'", "'('", "')'", "','", "'*'", "'.'",
  "$accept", "Program", "Stmt", "SysStmt", "DbStmt", "TbStmt", "IdxStmt",
  "FieldList", "Field", "Type", "WhereClause", "Op", "Expr", "SetClause",
  "SingleSetClause", "Selector", "TableList", "ColumnList", "Database",
  "Table", "Column", "TabledColumn", "ValueLists", "ValueList", "Value",
  "DbName", "TbName", "ColName", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    59,    40,    41,    44,    42,
      46
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -80,    34,   -80,    27,    -4,    -1,    -3,   -18,   -12,    18,
       1,    18,   -80,    13,    23,    28,    30,   -80,   -80,    -3,
      18,    18,    -3,    18,    18,   -80,   -80,   -80,    18,    18,
     -80,    44,   -80,   -80,   -80,    37,    24,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    31,    47,   -80,   -80,    48,
      68,    67,    94,    18,    94,    17,    94,    94,    54,    95,
     -28,   -80,    96,   -23,   -80,   -80,    80,    84,   -21,   -80,
      53,    60,    61,    77,    64,    59,    71,    65,   -80,    21,
      95,    94,    77,    95,    18,    70,    72,   -80,    17,    73,
      74,    75,   -80,   -80,    91,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,     9,   -80,    77,    95,    94,   -80,   -80,   -80,
     -80,   -80,   -80,    40,    81,    71,   -80,   -80,    71,   -80,
      94,    94,   -80,   114,   119,   120,   100,   -80,    77,    78,
      71,   -80,   101,   -80,   -80,   -80,   -80,   -80,    22,    82,
      83,    85,    86,   -80,   -80,   -80,   -80,    87,   -80,   -80,
     -80,    18,    88,    94,    89,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     8,    12,     0,
       0,     0,     0,     0,     0,    68,    11,    54,     0,     0,
      69,     0,    55,    70,    48,     0,    49,    52,    56,    15,
       4,     5,     6,     7,     9,     0,     0,    10,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,    50,    53,     0,     0,     0,    22,
       0,     0,     0,     0,    16,    70,    17,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    32,    31,    24,    20,    21,    63,    64,    66,
      67,    65,     0,    61,     0,     0,     0,    37,    38,    39,
      40,    41,    42,     0,     0,    18,    46,    47,    19,    51,
       0,     0,    23,     0,     0,     0,     0,    59,     0,    60,
      36,    58,     0,    34,    64,    33,    44,    43,     0,     0,
       0,     0,     0,    25,    62,    35,    26,     0,    28,    29,
      30,     0,     0,     0,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,    39,   -80,
     -44,   -80,   -80,   -80,    56,   -80,   -80,     8,    -9,    -5,
     -10,   -80,   -80,    35,   -79,   -80,   -80,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    68,    69,    94,
      76,   114,   135,    60,    61,    35,    63,    36,    26,    77,
      78,    79,    74,   102,   103,    27,    32,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    25,    80,   117,    31,    33,    39,    83,    28,    19,
      44,    20,    22,    47,    23,    45,    46,    29,    48,    49,
      81,    33,    30,    50,    51,    84,    87,    88,   107,   108,
     109,   110,   111,   112,     2,   137,   115,    21,    66,   118,
      24,    17,    62,    18,    65,    70,    71,    72,    64,   144,
      34,     3,     4,     5,     6,   113,   127,   128,    40,     7,
      67,   130,     8,   132,   133,     9,    53,    10,    41,   146,
      54,    62,    54,    42,    11,    43,    52,    55,    70,   119,
      97,    98,    99,   100,    97,   134,    99,   100,    89,    90,
      91,    92,    93,    56,    57,    58,   131,    59,    33,    75,
      73,   101,    85,    82,   136,   101,    86,    95,    96,   -69,
      37,   139,   104,   105,   126,   106,   120,   140,   121,   123,
     124,   125,   141,   142,   143,   145,   128,   122,   138,   147,
     148,   151,   149,   150,   153,     0,   155,   116,     0,   129,
       0,     0,     0,   154,     0,     0,   152
};

static const yytype_int16 yycheck[] =
{
      10,     4,    30,    82,     9,     4,    11,    30,    26,    13,
      19,    15,    13,    22,    15,    20,    21,    29,    23,    24,
      48,     4,     4,    28,    29,    48,    47,    48,     7,     8,
       9,    10,    11,    12,     0,   114,    80,    41,    21,    83,
      41,    14,    52,    16,    54,    55,    56,    57,    53,   128,
      49,    17,    18,    19,    20,    34,    47,    48,    45,    25,
      43,   105,    28,    23,    24,    31,    29,    33,    45,    47,
      48,    81,    48,    45,    40,    45,    32,    46,    88,    84,
       3,     4,     5,     6,     3,     4,     5,     6,    35,    36,
      37,    38,    39,    46,    46,    27,   106,    30,     4,     4,
      46,    24,    22,     7,   114,    24,    22,    47,    47,    50,
     120,   121,    48,    42,    23,    50,    46,     3,    46,    46,
      46,    46,     3,     3,    24,    24,    48,    88,   120,    47,
      47,    44,    47,    47,    46,    -1,    47,    81,    -1,   104,
      -1,    -1,    -1,   153,    -1,    -1,   151
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,     0,    17,    18,    19,    20,    25,    28,    31,
      33,    40,    53,    54,    55,    56,    57,    14,    16,    13,
      15,    41,    13,    15,    41,     4,    69,    76,    26,    29,
       4,    70,    77,     4,    49,    66,    68,    71,    78,    70,
      45,    45,    45,    45,    69,    70,    70,    69,    70,    70,
      70,    70,    32,    29,    48,    46,    46,    46,    27,    30,
      64,    65,    71,    67,    70,    71,    21,    43,    58,    59,
      71,    71,    71,    46,    73,     4,    61,    70,    71,    72,
      30,    48,     7,    30,    48,    22,    22,    47,    48,    35,
      36,    37,    38,    39,    60,    47,    47,     3,     4,     5,
       6,    24,    74,    75,    48,    42,    50,     7,     8,     9,
      10,    11,    12,    34,    62,    61,    65,    75,    61,    70,
      46,    46,    59,    46,    46,    46,    23,    47,    48,    74,
      61,    71,    23,    24,     4,    63,    71,    75,    68,    71,
       3,     3,     3,    24,    75,    24,    47,    47,    47,    47,
      47,    44,    70,    46,    71,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    76,    77,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     3,
       3,     2,     2,     6,     3,     2,     5,     5,     6,     6,
       6,     6,     1,     3,     2,     4,     5,    10,     4,     4,
       4,     1,     1,     3,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
			        (yyval.tree) = new Tree();
			    }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
			        (yyval.tree) = new Tree();
			        (yyval.tree)->stmtList.insert((yyval.tree)->stmtList.end(), (yyvsp[-1].tree)->stmtList.begin(), (yyvsp[0].tree)->stmtList.end());
			        (yyval.tree)->stmtList.push_back((Stmt*) (yyvsp[0].tree));
			    }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[-1].tree);
                }
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[-1].tree);
                }
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[-1].tree);
                }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[-1].tree);
                }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new SysStmt();
                }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new CreateDbStmt((Database*) (yyvsp[0].tree));
                }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new DropDbStmt((Database*) (yyvsp[0].tree));
	            }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new UseDbStmt((Database*) (yyvsp[0].tree));
	            }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new ShowDbStmt();
	            }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new CreateTbStmt((Table*) (yyvsp[-3].tree), &(yyvsp[-1].tree)->fieldList);
                }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 113 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new DropTbStmt((Table*) (yyvsp[0].tree));
                }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new DescTbStmt((Table*) (yyvsp[0].tree));
	            }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new InsertTbStmt((Table*) (yyvsp[-2].tree), &(yyvsp[0].tree)->valueList);
	            }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new DeleteTbStmt((Table*) (yyvsp[-2].tree), (WhereClause*) (yyvsp[0].tree));
	            }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new UpdateTbStmt((Table*) (yyvsp[-4].tree), (SetClause*) (yyvsp[-2].tree), (WhereClause*) (yyvsp[0].tree));
	            }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new SelectTbStmt(&(yyvsp[-4].tree)->columnList, &(yyvsp[-2].tree)->tableList, (WhereClause*) (yyvsp[0].tree));
	            }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new CreateIdxStmt((Table*) (yyvsp[-3].tree), (Column*) (yyvsp[-1].tree));
                }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new DropIdxStmt((Table*) (yyvsp[-3].tree), (Column*) (yyvsp[-1].tree));
                }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->fieldList.push_back((Field*) (yyvsp[0].tree));
                }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            (yyval.tree) = new Tree();
		            (yyval.tree)->fieldList.insert((yyval.tree)->fieldList.end(), (yyvsp[-2].tree)->fieldList.begin(), (yyvsp[-2].tree)->fieldList.end());
                    (yyval.tree)->fieldList.push_back((Field*) (yyvsp[0].tree));
		        }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new NormalField((Column*) (yyvsp[-1].tree), (Type*) (yyvsp[0].tree));
                }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new NotNullField((Column*) (yyvsp[-3].tree), (Type*) (yyvsp[-2].tree));
                }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new PrimaryField(&(yyvsp[-1].tree)->columnList);
	            }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new ForeignField((Column*) (yyvsp[-6].tree), (Table*) (yyvsp[-3].tree), (Column*) (yyvsp[-1].tree));
	            }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new IntType((yyvsp[-1].intVal));
                }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 185 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new VarcharType((yyvsp[-1].intVal));
	            }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new CharType((yyvsp[-1].intVal));
	            }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 193 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new TimeType();
	            }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 197 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new DoubleType();
	            }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 203 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new NormalWhereClause((TabledColumn*) (yyvsp[-2].tree), (Op*) (yyvsp[-1].opVal), (Expr*) (yyvsp[0].tree));
                }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 207 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
			        (yyval.tree) = new IsNullWhereClause((TabledColumn*) (yyvsp[-2].tree), false);
			    }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
			        (yyval.tree) = new IsNullWhereClause((TabledColumn*) (yyvsp[-3].tree), true);
			    }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 215 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
			        (yyval.tree) = new AndWhereClause((WhereClause*) (yyvsp[-2].tree), (WhereClause*) (yyvsp[0].tree));
			    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 221 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_EQ);
                }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 225 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_NE);
                }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 229 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_LT);
                }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 233 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_LE);
                }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 237 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_GT);
                }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 241 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.opVal) = new Op(Tree::OP_GE);
                }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 247 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new ValueExpr((Value*) (yyvsp[0].tree));
                }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 251 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new ColExpr((Column*) (yyvsp[0].tree));
	            }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 257 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    std::list<SingleSetClause*> singleList;
                    singleList.push_back((SingleSetClause*) (yyvsp[0].tree));
                    (yyval.tree) = new SetClause(&singleList);
                }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 263 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            std::list<SingleSetClause*>* beforeList = ((SetClause*) (yyvsp[-2].tree))->getSetClauseList();
		            std::list<SingleSetClause*> singleList;
		            singleList.insert(singleList.end(), beforeList->begin(), beforeList->end());
		            singleList.push_back((SingleSetClause*) (yyvsp[0].tree));
		            (yyval.tree) = new SetClause(&singleList);
		        }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 273 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new SingleSetClause((Column*) (yyvsp[-2].tree), (Value*) (yyvsp[0].tree));
                }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 278 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    // Tree.columnList 是空的
                }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 282 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            (yyval.tree) = new Tree();
		            (yyval.tree)->columnList = (yyvsp[0].tree)->columnList;
		        }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 289 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->tableList.push_back((Table*) (yyvsp[0].tree));
                }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 294 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            (yyval.tree) = new Tree();
		            (yyval.tree)->tableList.insert((yyval.tree)->tableList.end(), (yyvsp[-2].tree)->tableList.begin(), (yyvsp[-2].tree)->tableList.end());
		            (yyval.tree)->tableList.push_back((Table*) (yyvsp[0].tree));
		        }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 302 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->columnList.push_back((Column*) (yyvsp[0].tree));
                }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 307 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            (yyval.tree) = new Tree();
		            (yyval.tree)->columnList.insert((yyval.tree)->columnList.end(), (yyvsp[-2].tree)->columnList.begin(), (yyvsp[-2].tree)->columnList.end());
		            (yyval.tree)->columnList.push_back((Column*) (yyvsp[0].tree));
		        }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 315 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Database((yyvsp[0].identVal));
                }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 320 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Table((yyvsp[0].identVal));
                }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 326 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Column((yyvsp[0].identVal));
                }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 333 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new TabledColumn((Column*) (yyvsp[0].tree));
                }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 337 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new TabledColumn((Table*) (yyvsp[-2].tree), (Column*) (yyvsp[0].tree));
                }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 343 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->valueLists.push_back((yyvsp[-1].tree)->valueList);
                }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 348 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
		            (yyval.tree) = new Tree();
                    (yyval.tree)->valueLists.insert((yyval.tree)->valueLists.end(), (yyvsp[-2].tree)->valueLists.begin(), (yyvsp[-2].tree)->valueLists.end());
                    (yyval.tree)->valueLists.push_back((yyvsp[0].tree)->valueList);
		        }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 356 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->valueList.push_back((Value*) (yyvsp[0].tree));
                }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 361 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new Tree();
                    (yyval.tree)->valueList.insert((yyval.tree)->valueList.end(), (yyvsp[-2].tree)->valueList.begin(), (yyvsp[-2].tree)->valueList.end());
                    (yyval.tree)->valueList.push_back((Value*) (yyvsp[0].tree));
                }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 369 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new IntValue((yyvsp[0].intVal));
                }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 373 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = new StringValue((yyvsp[0].stringVal));
                }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 377 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new NullValue();
	            }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 381 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new DoubleValue((yyvsp[0].doubleVal));
	            }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 385 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
	                (yyval.tree) = new TimeValue((yyvsp[0].timeVal));
	            }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 391 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.identVal) = new Identifier((yyvsp[0].stringVal));
                }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 396 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.identVal) = new Identifier((yyvsp[0].stringVal));
                }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 401 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1646  */
    {
                    (yyval.identVal) = new Identifier((yyvsp[0].stringVal));
                }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1989 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 405 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1906  */


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

        cout << "DEBUG: Has been processing" << endl;
        cout.flush();

        /* If a query was successfully read, interpret it */
        if(i == 0 && yyval.tree != nullptr) {
            cout << "DEBUG: ready to print" << endl;
            cout.flush();
            yyval.tree->print();
        }

        cout << "DEBUG: Finished processing" << endl;
        cout.flush();
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
