%{
#include <cstring>
#include "parser.h"  // 由YACC自动生成
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
"NULL"                          { return NULL; }
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
"INT"                           { return INT; }
"VARCHAR"                       { return VARCHAR; }
"DESC"                          { return DESC; }
"REFERENCES"                    { return REFERENCES; }
"INDEX"                         { return INDEX; }
"AND"                           { return AND; }
"DATE"                          { return DATE; }
"FLOAT"                         { return FLOAT; }
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
"null"                          { return NULL; }
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
"int"                           { return INT; }
"varchar"                       { return VARCHAR; }
"desc"                          { return DESC; }
"references"                    { return REFERENCES; }
"index"                         { return INDEX; }
"and"                           { return AND; }
"date"                          { return DATE; }
"float"                         { return FLOAT; }
"foreign"                       { return FOREIGN; }

">="                            { return GE; }
">"                             { return GT; }
"="                             { return EQ; }
"<"                             { return LT; }
"<="                            { return LE; }
"<>"                            { return NE; }

[A-Za-z][_0-9A-Za-z]*			{
                                    // 标识符
									yylval.identVal = copy_string(yytext, yyleng);
									return IDENTIFIER;
								}

[0-9]+							{
                                    // 整数
									yylval.intVal = atoi(yytext);
									return VALUE_INTEGER;
								}

'[^']*'							{
                                    // string
									yylval.stringVal = copy_string(yytext, yyleng);
									return VALUE_STRING;
								}
%%
#include "scanhelp.c"
