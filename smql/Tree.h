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
            ((Tree*) (*i))->print();
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

// <table>  := <tbName>
class Table: public Tree {
private:
    Identifier* tbName;

public:
    explicit Table(Identifier* tbName): tbName(tbName) { }

    Identifier* getTbName() {
        return tbName;
    }

    void print() override {
        IndentOstream::write("Table: ");
        IndentOstream::write(tbName->getName());
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

    void print() override {
        IndentOstream::write("Column: ");
        IndentOstream::write(colName->getName());
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

    void print() override {
        IndentOstream::write("TabledColumn: ");
        IndentOstream::incIndent();
        table->print();
        column->print();
    }
};

/**
 * 类型
 */
class Type: public Tree {
public:
    enum kind {
        INT, VARCHAR, CHAR, TIME, DOUBLE
    };

    explicit Type() = default;

    virtual kind getKind() const = 0;
};

class IntType: public Type {
private:
    int length;
public:
    explicit IntType(const int& length): length(length) { }

    kind getKind() const override {
        return kind::INT;
    }

    int getLength() const {
        return length;
    }

    void print() override {
        IndentOstream::write("type int");
    }
};

class VarcharType: public Type {
private:
    int length;

public:
    explicit VarcharType(const int& length): length(length) { }

    kind getKind() const override {
        return kind::VARCHAR;
    }

    int getLength() const {
        return length;
    }

    void print() override {
        IndentOstream::write("type varchar");
    }
};

class CharType: public Type {
private:
    int length;

public:
    explicit CharType(const int& length): length(length) { }

    kind getKind() const override {
        return kind::VARCHAR;
    }

    int getLength() const {
        return length;
    }

    void print() override {
        IndentOstream::write("type char");
    }
};

class TimeType: public Type {
public:
    explicit TimeType() = default;

    kind getKind() const override {
        return kind::TIME;
    }

    void print() override {
        IndentOstream::write("type time");
    }
};

class DoubleType: public Type {
public:
    explicit DoubleType() = default;

    kind getKind() const override {
        return kind::DOUBLE;
    }

    void print() override {
        IndentOstream::write("type double");
    }
};

class Value: public Tree {
public:
    enum kind {
        INT, STRING, NULL_VALUE, DOUBLE, TIME
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

    void print() override {
        IndentOstream::writeAppend("value int ");
        IndentOstream::write(value);
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
        return kind::STRING;
    }

    void print() override {
        IndentOstream::writeAppend("value string ");
        IndentOstream::writeAppend("\'");
        IndentOstream::writeAppend(value);
        IndentOstream::writeAppend("\'");
    }
};

class DoubleValue: public Value {
private:
    double value;

public:
    explicit DoubleValue(double value): value(value) { }

    kind getKind() const override {
        return kind::DOUBLE;
    }

    double getValue() const {
        return value;
    }

    void print() override {
        IndentOstream::writeAppend("value double ");
        IndentOstream::write(value);
    }
};

class TimeValue: public Value {
private:
    struct tm value;

public:
    explicit TimeValue(struct tm value): value(value) { }

    kind getKind() const override {
        return kind::TIME;
    }

    struct tm getValue() const {
        return value;
    }

    void print() override {
        IndentOstream::write("value time ");
        IndentOstream::write(value.tm_sec);
    }
};

class NullValue: public Value {
public:
    explicit NullValue() = default;

    kind getKind() const override {
        return kind::NULL_VALUE;
    }

    void print() override {
        IndentOstream::write("value NULL");
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

    void print() override {
        IndentOstream::write("Field");
        IndentOstream::incIndent();
        type->print();
        column->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("Field not null");
        IndentOstream::incIndent();
        type->print();
        column->print();
        IndentOstream::decIndent();
    }
};

// PRIMARY KEY '(' <colList> ')'
class PrimaryField: public Field {
private:
    list<Column*>* columnList;
public:
    explicit PrimaryField(std::list<Column*>* columnList): columnList(columnList) { }

    list<Column*>* getColumnList() {
        return columnList;
    }

    kind getKind() const override {
        return kind::PRIMARY;
    }

    void print() override {
        IndentOstream::write("Field Primary");
        IndentOstream::incIndent();
        IndentOstream::write("Column List");
        IndentOstream::incIndent();
        for (auto i = columnList->begin(); i != columnList->end(); i++) {
            ((Column*) (*i))->print();
        }
        IndentOstream::decIndent();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("Field Foreign Key");
        IndentOstream::incIndent();
        column->print();
        table->print();
        referredColumn->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("Database: ");
        IndentOstream::write(dbName->getName());
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

    void print() override {
        IndentOstream::writeAppend("Op: ");
        if (op == Tree::OP_EQ)
            IndentOstream::write("=");
        else if (op == Tree::OP_GE)
            IndentOstream::write(">=");
        else if (op == Tree::OP_GT)
            IndentOstream::write(">");
        else if (op == Tree::OP_LE)
            IndentOstream::write("<=");
        else if (op == Tree::OP_LT)
            IndentOstream::write("<");
        else if (op == Tree::OP_NE)
            IndentOstream::write("<>");
        else
            IndentOstream::write("error");
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

    void print() override {
        IndentOstream::write("ValueExpr: ");
        IndentOstream::incIndent();
        value->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("ColExpr: ");
        IndentOstream::incIndent();
        column->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("WhereClause: ");
        IndentOstream::incIndent();
        column->print();
        op->print();
        expr->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("WhereClause: ");
        IndentOstream::incIndent();
        column->print();
        if (hasNot)
            IndentOstream::write("NOT");
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("WhereClause: ");
        IndentOstream::incIndent();
        whereClause[0]->print();
        whereClause[1]->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("SetClause: ");
        IndentOstream::incIndent();
        column->print();
        value->print();
        IndentOstream::decIndent();
    }
};

// <setClause> := <setClause> ',' <colName> '=' <value>
class SetClause: public Clause {
private:
    list<SingleSetClause*>* setClauseList;

public:
    explicit SetClause(list<SingleSetClause*>* setClauseList): setClauseList(setClauseList) { }

    list<SingleSetClause*>* getSetClauseList() {
        return setClauseList;
    }

    void print() override {
        IndentOstream::write("SetClauseList: ");
        IndentOstream::incIndent();
        for (auto &i : *setClauseList) {
            ((SingleSetClause*) i)->print();
        }
        IndentOstream::decIndent();
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
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("DescTbStmt");
        IndentOstream::incIndent();
        table->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("InsertTbStmt");
        IndentOstream::incIndent();
        table->print();
        for (auto &i : *valueList) {
            ((Value*) i)->print();
        }
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("DeleteTbStmt");
        IndentOstream::incIndent();
        table->print();
        whereClause->print();
        IndentOstream::decIndent();
    }
};

// UPDATE <table> SET <setClause> WHERE <whereClause>
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

    void print() override {
        IndentOstream::write("UpdateTbStmt");
        IndentOstream::incIndent();
        table->print();
        setClause->print();
        whereClause->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("SelectTbStmt");
        IndentOstream::incIndent();
        IndentOstream::write("Selector");
        for (auto &i : *selector) {
            ((Column*) i)->print();
        }
        IndentOstream::write("TableList");
        for (auto &i : *tableList) {
            ((Table*) i)->print();
        }
        whereClause->print();
        IndentOstream::decIndent();
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

    void print() override {
        IndentOstream::write("CreateIdxStmt");
        IndentOstream::incIndent();
        table->print();
        column->print();
        IndentOstream::decIndent();
    }
};

// <idxStmt>  := DROP INDEX <tbName> '(' <colName> ')'
class DropIdxStmt: public IdxStmt {
public:
    DropIdxStmt(Table* table, Column* column): IdxStmt(table, column) { }

    kind getKind() const override {
        return kind::DROP;
    }

    void print() override {
        IndentOstream::write("DropIdxStmt");
        IndentOstream::incIndent();
        table->print();
        column->print();
        IndentOstream::decIndent();
    }
};

#endif //MYDB_TREE_H
