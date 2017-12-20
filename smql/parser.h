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
typedef union{
    int intVal;
    char *stringVal;
    Op *opVal;
    Identifier *identVal;
    Tree *tree;
} YYSTYPE;
extern YYSTYPE yylval;