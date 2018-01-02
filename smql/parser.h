/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 15 "/home/zhanghuimeng/文档/DB_project/db/smql/parser.y" /* yacc.c:1909  */

    int intVal;
    char *stringVal;
    double doubleVal;
    struct tm timeVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;

#line 152 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
