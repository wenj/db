//
// Created by lenovo on 2017/12/21.
//

#ifndef MYDB_YYSTYPE_H
#define MYDB_YYSTYPE_H

#include <time.h>

struct Op typedef Op;
struct Identifier typedef Identifier;
struct Tree typedef Tree;

typedef union {
    int intVal;
    char *stringVal;
    double doubleVal;
    struct tm timeVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;
} YYSTYPE;

struct PF_Manager typedef PF_Manager;
struct SM_Manager typedef SM_Manager;

void Parse();

void yyerror(char const *s);

int yywrap(void);

#endif //MYDB_YYSTYPE_H
