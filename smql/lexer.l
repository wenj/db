%{
#include <string.h>
#include <time.h>
#include "strptime.h"
#include "parser.h"  // 由YACC自动生成
#include "YYSTYPE.h"
#include "redbase.h"

static char *copy_string(char *s, int len);

static struct tm parse_date(char* s);

extern YYSTYPE yylval;  // patch（也不知道为啥）
%}

%%

"DATABASE"                      { return DATABASE; }
"DATABASES"                     { return DATABASES; }
"TABLE"                         { return TABLE; }
"TABLES"                        { return TABLES; }
"SHOW"                          { return SHOW; }
"CREATE"                        { return CREATE; }
"DROP"                          { return DROP; }
"USE"                           { return USE; }
"PRIMARY"                       { return PRIMARY; }
"KEY"                           { return KEY; }
"NOT"                           { return NOT; }
"NULL"                          { return NULL_D; }
"INSERT"                        { return INSERT; }
"INTO"                          { return INTO; }
"VALUES"                        { return VALUES; }
"DELETE"                        { return DELETE; }
"FROM"                          { return FROM; }
"WHERE"                         { return WHERE; }
"UPDATE"                        { return UPDATE; }
"SET"                           { return SET; }
"SELECT"                        { return SELECT; }
"IS"                            { return IS; }
"INT"                           { return INT_D; }
"VARCHAR"                       { return VARCHAR; }
"DESC"                          { return DESC; }
"REFERENCES"                    { return REFERENCES; }
"INDEX"                         { return INDEX; }
"AND"                           { return AND; }
"DATE"                          { return DATE; }
"FLOAT"                         { return FLOAT_D; }
"FOREIGN"                       { return FOREIGN; }
"database"                      { return DATABASE; }
"databases"                     { return DATABASES; }
"table"                         { return TABLE; }
"tables"                        { return TABLES; }
"show"                          { return SHOW; }
"create"                        { return CREATE; }
"drop"                          { return DROP; }
"use"                           { return USE; }
"primary"                       { return PRIMARY; }
"key"                           { return KEY; }
"not"                           { return NOT; }
"null"                          { return NULL_D; }
"insert"                        { return INSERT; }
"into"                          { return INTO; }
"values"                        { return VALUES; }
"delete"                        { return DELETE; }
"from"                          { return FROM; }
"where"                         { return WHERE; }
"update"                        { return UPDATE; }
"set"                           { return SET; }
"select"                        { return SELECT; }
"is"                            { return IS; }
"int"                           { return INT_D; }
"varchar"                       { return VARCHAR; }
"desc"                          { return DESC; }
"references"                    { return REFERENCES; }
"index"                         { return INDEX; }
"and"                           { return AND; }
"date"                          { return DATE; }
"float"                         { return FLOAT_D; }
"foreign"                       { return FOREIGN; }

">="                            { return GE; }
">"                             { return GT; }
"="                             { return EQ; }
"<"                             { return LT; }
"<="                            { return LE; }
"<>"                            { return NE; }

[A-Za-z][_0-9A-Za-z]*			{
                                    // 标识符
									yylval.stringVal = copy_string(yytext, yyleng);
									return VALUE_STRING;
								}

[0-9]+							{
                                    // 整数
									yylval.intVal = atoi(yytext);
									return VALUE_INTEGER;
								}

\'[^\']*\'						{
                                    // 字符串
									yylval.stringVal = copy_string(yytext, yyleng);
									return VALUE_STRING;
								}

[-+]?[0-9]*\.[0-9]+             {
                                    // 浮点数
                                    yylval.doubleVal = atof(yytext);
                                    return VALUE_DOUBLE;
                                }
\d{1,4}\/\d{1,2}\/\d{1,2}       {
                                    // 日期格式：yyyy/mm/dd
                                    yylval.timeVal = parse_date(yytext);
                                    return VALUE_TIME;
                                }

%%

// 复制串
static char *copy_string(char *s, int len)
{
   char *copy = (char*) malloc(len + 1);
   strncpy(copy, s, len);
   copy[len] = '\0';
   return copy;
}

// 处理日期输入
static struct tm parse_date(char* s)
{
    struct tm when;
    strptime(s, "%y/%d/%m", &when);
    return when;
}