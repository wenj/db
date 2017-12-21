//
// Created by lenovo on 2017/12/20.
//

#ifndef MYDB_TREE_H
#define MYDB_TREE_H

#include <list>
#include <utility>
#include <cstring>

#include "IndentOstream.h"

using namespace std;

/**
 * 现在的问题之一是要用指针来指一切……
 */

class Identifier;
class Type;
class Value;
class Stmt;
class Column;
class Table;
class Field;

class Tree {
public:
    // 定义Operator
    static const int OP_GE;
    static const int OP_GT;
    static const int OP_EQ;
    static const int OP_LT;
    static const int OP_LE;
    static const int OP_NE;

    list<Stmt*> stmtList;
    list<Column*> columnList;
    list<Table*> tableList;
    list<Value*> valueList;
    list<std::list<Value*>> valueLists;
    list<Field*> fieldList;

    /*
    Tree() {
        stmtList = new std::list<Stmt*>();
        columnList = new std::list<Column*>();
        tableList = new std::list<Identifier*>();
        valueList = new std::list<Value*>();
        valueLists = new std::list<std::list<Value*>>();
        fieldList = new std::list<Field*>();
    }
     */

    // Print the program
    virtual void print() {
        IndentOstream::write("program");
        IndentOstream::incIndent();
        auto i = stmtList.begin();
        while (i != stmtList.end()) {
            (*i)->print();
            i++;
        }
        IndentOstream::decIndent();
    }
};

/**
* 标识符（数据库名称、列名）
*/
class Identifier: public Tree {
private:
    char* name;

public:
    Identifier() {
        name = nullptr;
    }

    /*
    // 因为在lexer里面已经copy_string过了
    explicit Identifier(const char* name) {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
     */

    explicit Identifier(char* name): name(name) { }

    char* getName() const {
        return name;
    }
};

/**
 * 类型
 */
class Type: public Tree {
protected:
    int length;

public:
    enum kind {
        INT, VARCHAR
    };

    explicit Type(const int& length): length(length) { }

    virtual kind getKind() const = 0;
};

class IntType: public Type {
public:
    explicit IntType(const int& length): Type(length) { }

    kind getKind() const override {
        return kind::INT;
    }
};

class VarcharType: public Type {
public:
    explicit VarcharType(const int& length): Type(length) { }

    kind getKind() const override {
        return kind::VARCHAR;
    }
};

class Value: public Tree {
public:
    enum kind {
        INT, STRING, NULL_VALUE
    };

    virtual kind getKind() const = 0;
};

class IntValue: public Value {
private:
    int value;

public:
    explicit IntValue(const int& value): value(value) { }

    int getValue() const {
        return value;
    }

    kind getKind() const override {
        return kind::INT;
    }
};

class StringValue: public Value {
private:
    char* value;

public:
    explicit StringValue(const char* value) {
        this->value = new char[strlen(value)];
        strcpy(this->value, value);
    }

    char* getValue() const {
        return value;
    }

    kind getKind() const override {
        return kind::INT;
    }
};

class NullValue: public Value {
public:
    explicit NullValue() = default;

    kind getKind() const override {
        return kind::NULL_VALUE;
    }
};

/**
 * Field是什么呢？？
 */
class Field: public Tree {
public:
    enum kind {
        NORMAL, NOT_NULL, PRIMARY, FOREIGN
    };

    explicit Field() = default;

    virtual kind getKind() const = 0;
};

// <column> <type>
class NormalField: public Field {
private:
    Type* type;
    Column* column;

public:
    NormalField(Column* column, Type* type): column(column), type(type) { }

    kind getKind() const override {
        return kind::NORMAL;
    }

    Type* getType() const {
        return type;
    }

    Column* getColumn() const {
        return column;
    }
};

// <column> <type> NOT NULL
class NotNullField: public Field {
private:
    Type* type;
    Column* column;

public:
    NotNullField(Column* column, Type* type): column(column), type(type) { }

    kind getKind() const override {
        return kind::NOT_NULL;
    }

    Type* getType() const {
        return type;
    }

    Column* getColumn() const {
        return column;
    }
};

// PRIMARY KEY '(' <colList> ')'
class PrimaryField: public Field {
private:
    std::list<Column*>* columnList;
public:
    explicit PrimaryField(std::list<Column*>* columnList): columnList(columnList) { }

    std::list<Column*>* getColumnList() {
        return columnList;
    }

    kind getKind() const override {
        return kind::PRIMARY;
    }
};

// 似乎是扩展功能
// FOREIGN KEY '(' <column> ')' REFERENCES <table> '(' <column> ')'
class ForeignField: public Field {
private:
    Column* column;
    Table* table;
    Column* referredColumn;

public:
    ForeignField(Column* column, Table* table, Column* referredColumn): column(column), table(table),
                                                                        referredColumn(referredColumn) { }

    Column* getColumn() {
        return column;
    }

    Table* getTable() {
        return table;
    }

    kind getKind() const override {
        return kind::FOREIGN;
    }
};

// <database>  := <dbName>
class Database: public Tree {
private:
    Identifier* dbName;

public:
    explicit Database(Identifier* dbName): dbName(dbName) { }

    Identifier* getDbName() {
        return dbName;
    }
};

// <table>  := <tbName>
class Table: public Tree {
private:
    Identifier* tbName;

public:
    explicit Table(Identifier* tbName): tbName(tbName) { }

    Identifier* getTbName() {
        return tbName;
    }
};

// <column>  := <colName>
class Column: public Tree {
private:
    Identifier* colName;

public:
    explicit Column(Identifier* colName): colName(colName) { }

    Identifier* getColName() {
        return colName;
    }
};

// <tabledColumn>  := <table> '.' <column>
class TabledColumn: public Tree {
private:
    Table* table;
    Column* column;

public:
    explicit TabledColumn(Column* column): table(nullptr), column(column) { }

    explicit TabledColumn(Table* table, Column* column): table(table), column(column) { }

    Table* getTable() {
        return table;
    }

    Column* getColumn() {
        return column;
    }
};

// <op>  := '=' | '<>' | '<=' | '>=' | '<' | '>'
class Op: public Tree {
private:
    int op;

public:
    explicit Op(const int& op): op(op) { }

    int getOp() const {
        return op;
    }
};

// <expr>  := <value> | <col>
class Expr: public Tree {
public:
    enum kind {
        VALUE, COL
    };

    virtual kind getKind() const = 0;
};

class ValueExpr: public Expr {
private:
    Value* value;

public:
    explicit ValueExpr(Value* value): value(value) { }

    Value* getValue() {
        return value;
    }

    kind getKind() const override {
        return kind::VALUE;
    }
};

class ColExpr: public Expr {
private:
    Column* column;

public:
    explicit ColExpr(Column* column): column(column) { }

    Column* getColumn() {
        return column;
    }

    kind getKind() const override {
        return kind::COL;
    }
};

class Clause: public Tree {

};

// <whereClause>  := <col><op><expr> | <col> IS [NOT] NULL | <whereClause> AND <whereClause>
class WhereClause: public Clause {
public:
    enum kind {
        NORMAL, IS_NULL, AND
    };

    virtual kind getKind() const = 0;
};

// <whereClause>  := <col><op><expr>
class NormalWhereClause: public WhereClause {
private:
    TabledColumn* column;
    Op* op;
    Expr* expr;

public:
    NormalWhereClause(TabledColumn* column, Op* op, Expr* expr): column(column), op(op), expr(expr) { }

    TabledColumn* getColumn() {
        return column;
    }

    Op* getOp() {
        return op;
    }

    Expr* getExpr() {
        return expr;
    }

    kind getKind() const override {
        return kind::NORMAL;
    }
};

// <whereClause>  := <col> IS [NOT] NULL
class IsNullWhereClause: public WhereClause {
private:
    TabledColumn* column;
    bool hasNot;

public:
    IsNullWhereClause(TabledColumn* column, bool hasNot): column(column), hasNot(hasNot) { }

    TabledColumn* getColumn() {
        return column;
    }

    bool getHasNot() const {
        return hasNot;
    }

    kind getKind() const override {
        return kind::IS_NULL;
    }
};

// <whereClause>  := <whereClause> AND <whereClause>
class AndWhereClause: public WhereClause {
private:
    WhereClause* whereClause[2];

public:
    explicit AndWhereClause(WhereClause* whereClause1, WhereClause* whereClause2) {
        whereClause[0] = whereClause1;
        whereClause[1] = whereClause2;
    }

    WhereClause* getWhereClause(int i) {
        return whereClause[i % 2];
    }

    kind getKind() const override {
        return kind::AND;
    }
};

// <setClause>  := <column> '=' <value>
class SingleSetClause: public Clause {
private:
    Column* column;
    Value* value;

public:
    explicit SingleSetClause(Column* column, Value* value): column(column), value(value) { }

    Column* getColumn() {
        return column;
    }

    Value* getValue() {
        return value;
    }
};

// <setClause> := <setClause> ',' <colName> '=' <value>
class SetClause: public Clause {
private:
    std::list<SingleSetClause*>* setClauseList;

public:
    explicit SetClause(std::list<SingleSetClause*>* setClauseList): setClauseList(setClauseList) { }

    std::list<SingleSetClause*>* getSetClauseList() {
        return setClauseList;
    }
};

class Stmt: public Tree {

};

// 只有一种指令：
// SHOW DATABASES
class SysStmt: public Stmt {
public:
    SysStmt() = default;

    void print() override {
        IndentOstream::write("SysStmt: Show Database");
    }
};

class DbStmt: public Stmt {
public:
    enum kind {
        CREATE, DROP, USE, SHOW_TABLE
    };

    virtual kind getKind() const = 0;
};

// CREATE DATABASE <database>
class CreateDbStmt: public DbStmt {
private:
    Database* database;
public:
    explicit CreateDbStmt(Database* database): database(database) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Database* getDatabase() const {
        return database;
    }

    void print() override {
        IndentOstream::write("CreateDbStmt: Create Database");
        IndentOstream::incIndent();
        database->print();
        IndentOstream::decIndent();
    }
};

// DROP DATABASE <database>
class DropDbStmt: public DbStmt {
private:
    Database* database;
public:
    explicit DropDbStmt(Database* database): database(database) { }

    kind getKind() const override {
        return kind::DROP;
    }

    Database* getDatabase() const {
        return database;
    }

    void print() override {
        IndentOstream::write("DropDbStmt: Drop Database");
        IndentOstream::incIndent();
        database->print();
        IndentOstream::decIndent();
    }
};

// USE <database>
class UseDbStmt: public DbStmt {
private:
    Database* database;
public:
    explicit UseDbStmt(Database* database): database(database) { }

    kind getKind() const override {
        return kind::USE;
    }

    Database* getDatabase() const {
        return database;
    }

    void print() override {
        IndentOstream::write("UseDbStmt: Use Database");
        IndentOstream::incIndent();
        database->print();
        IndentOstream::decIndent();
    }
};

// SHOW TABLES
class ShowDbStmt: public DbStmt {
public:
    ShowDbStmt() = default;

    kind getKind() const override {
        return kind::SHOW_TABLE;
    }

    void print() override {
        IndentOstream::write("ShowDbStmt: Show Tables");
    }
};

class TbStmt: public Stmt {
public:
    enum kind {
        CREATE, DROP, DESC, INSERT, DELETE, UPDATE, SELECT
    };

    virtual kind getKind() const = 0;
};

// CREATE TABLE <table> '('<fieldList>')'
class CreateTbStmt: public TbStmt {
private:
    Table* table;
    list<Field*>* fieldList;

public:
    CreateTbStmt(Table* table, std::list<Field*>* fieldList): table(table), fieldList(fieldList) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Table* getTable() const {
        return table;
    }

    std::list<Field*>* getFieldList() {
        return fieldList;
    }

    void print() override {
        IndentOstream::write("CreateTbStmt: Create Table");
        IndentOstream::incIndent();
        table->print();
        IndentOstream::incIndent();
        IndentOstream::write("FieldList");
        IndentOstream::incIndent();
        for (list<Field*>::iterator i; i != fieldList->end(); i++) {
            (*i)->print();
        }
        IndentOstream::decIndent();
        IndentOstream::decIndent();
        IndentOstream::decIndent();
    }
};

// DROP TABLE <table>
class DropTbStmt: public TbStmt {
private:
    Table* table;

public:
    explicit DropTbStmt(Table* table): table(table) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Table* getTable() const {
        return table;
    }

    void print() override {
        IndentOstream::write("DropTbStmt: Drop Table");
        IndentOstream::incIndent();
        table->print();
    }
};

// DESC <tbName>
class DescTbStmt: public TbStmt {
private:
    Table* table;

public:
    explicit DescTbStmt(Table* table): table(table) { }

    kind getKind() const override {
        return kind::DESC;
    }

    Table* getTable() const {
        return table;
    }
};

// INSERT INTO <tbName> VALUES <valueLists>
class InsertTbStmt: public TbStmt {
private:
    Table* table;
    std::list<Value*>* valueList;

public:
    InsertTbStmt(Table* table, std::list<Value*>* valueList): table(table), valueList(valueList) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Table* getTable() const {
        return table;
    }

    std::list<Value*>* getValueList() {
        return valueList;
    }
};

// DELETE FROM <tbName> WHERE <whereClause>
class DeleteTbStmt: public TbStmt {
private:
    Table* table;
    WhereClause* whereClause;

public:
    explicit DeleteTbStmt(Table* table, WhereClause* whereClause): table(table), whereClause(whereClause) { }

    Table* getTable() const {
        return table;
    }

    WhereClause* getWhereClause() {
        return whereClause;
    }

    kind getKind() const override {
        return kind::DELETE;
    }
};

// UPDATE <tbName> SET <setClause> WHERE <whereClause>
class UpdateTbStmt: public TbStmt {
private:
    Table* table;
    SetClause* setClause;
    WhereClause* whereClause;

public:
    explicit UpdateTbStmt(Table* table, SetClause* setClause, WhereClause* whereClause): table(table),
                                                                                               setClause(setClause),
                                                                                               whereClause(whereClause) { }

    Table* getTable() const {
        return table;
    }

    SetClause* getSetClause() {
        return setClause;
    }

    WhereClause* getWhereClause() {
        return whereClause;
    }

    kind getKind() const override {
        return kind::UPDATE;
    }
};

// SELECT <selector> FROM <tableList> WHERE <whereClause>
// <selector>  := '*' | <col> [',' <col>]*
class SelectTbStmt: public TbStmt {
private:
    std::list<Column*>* selector; // 为null时表示*
    std::list<Table*>* tableList;
    WhereClause* whereClause;

public:
    SelectTbStmt(std::list<Column*>* selector, std::list<Table*>* tableList, WhereClause* whereClause): selector(selector),
                                                                                                           tableList(tableList),
                                                                                                           whereClause(whereClause) { }

    std::list<Column*>* getSelector() {
        return selector;
    }

    std::list<Table*>* getTableList() {
        return tableList;
    }

    WhereClause* getWhereClause() {
        return whereClause;
    }

    kind getKind() const override {
        return kind::SELECT;
    }
};

class IdxStmt: public Stmt {
protected:
    Table* table;
    Column* column;

public:
    enum kind {
        CREATE, DROP
    };

    IdxStmt(Table* table, Column* column): table(table), column(column) { }

    Table* getTable() {
        return table;
    }

    Column* getColumn() {
        return column;
    }

    virtual kind getKind() const = 0;
};

// <idxStmt>  := CREATE INDEX <table> '(' <column> ')'
class CreateIdxStmt: public IdxStmt {
public:
    CreateIdxStmt(Table* table, Column* column): IdxStmt(table, column) { }

    kind getKind() const override {
        return kind::CREATE;
    }
};

// <idxStmt>  := DROP INDEX <tbName> '(' <colName> ')'
class DropIdxStmt: public IdxStmt {
public:
    DropIdxStmt(Table* table, Column* column): IdxStmt(table, column) { }

    kind getKind() const override {
        return kind::DROP;
    }
};

#endif //MYDB_TREE_H
