//
// Created by lenovo on 2017/12/20.
//

#ifndef MYDB_TREE_H
#define MYDB_TREE_H

#include <list>
#include <utility>
#include <cstring>

/**
 * 现在的问题之一是要用指针来指一切……
 */

class Identifier;
class Type;
class Value;
class Stmt;
class Column;

class Tree {
public:
    // 定义Operator
    static const int GE = 1;
    static const int GT = GE + 1;
    static const int EQ = GT + 1;
    static const int LT = EQ + 1;
    static const int LE = LT + 1;
    static const int NE = LE + 1;

    std::list<Stmt*> stmtList;
    std::list<Column*> columnList;
    std::list<Identifier*> tableList;
    std::list<Value*> valueList;
    std::list<std::list<Value*>> valueLists;
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
protected:
    Identifier* colName;
public:
    enum kind {
        NORMAL, NOT_NULL, PRIMARY
    };

    explicit Field(Identifier* colName): colName(colName) { }

    Identifier* getColName() const {
        return colName;
    }

    virtual kind getKind() const = 0;
};

// <colName> <type>
class NormalField: public Field {
private:
    Type* type;

public:
    NormalField(Identifier* colName, Type* type): Field(colName), type(type) { }

    kind getKind() const override {
        return kind::NORMAL;
    }

    Type* getType() const {
        return type;
    }
};

// <colName> <type> NOT NULL
class NotNullField: public Field {
private:
    Type* type;

public:
    NotNullField(Identifier* colName, Type* type): Field(colName), type(type) { }

    kind getKind() const override {
        return kind::NOT_NULL;
    }

    Type* getType() const {
        return type;
    }
};

// PRIMARY KEY '(' <colName> ')'
class PrimaryField: public Field {
public:
    explicit PrimaryField(Identifier* colName): Field(colName) { }

    kind getKind() const override {
        return kind::PRIMARY;
    }
};

// <col>  := [<tbName> '.'] <colName>
class Column: public Tree {
private:
    Identifier* tbName;
    Identifier* colName;

public:
    explicit Column(Identifier* tbName, Identifier* colName): tbName(tbName), colName(colName) { }

    explicit Column(Identifier* colName): tbName(nullptr), colName(colName) { }

    Identifier* getTbName() {
        return tbName;
    }

    Identifier* getColName() {
        return colName;
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
    Column* column;
    Op* op;
    Expr* expr;

public:
    NormalWhereClause(Column* column, Op* op, Expr* expr): column(column), op(op), expr(expr) { }

    Column* getColumn() {
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
    Column* column;
    bool hasNot;

public:
    IsNullWhereClause(Column* column, bool hasNot): column(column), hasNot(hasNot) { }

    Column* getColumn() {
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

// <setClause>  := <colName> '=' <value>
class SingleSetClause: public Clause {
private:
    Identifier* colName;
    Value* value;

public:
    explicit SingleSetClause(Identifier* colName, Value* value): colName(colName), value(value) { }

    Identifier* getColName() {
        return colName;
    }

    Value* getValue() {
        return value;
    }
};

// <setClause> := <setClause> ',' <colName> '=' <value>
class SetClause: public Clause {
private:
    std::list<SingleSetClause>* setClauseList;

public:
    explicit SetClause(std::list<SingleSetClause>* setClauseList): setClauseList(setClauseList) { }

    std::list<SingleSetClause>* getSetClauseList() {
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
};

class DbStmt: public Stmt {
public:
    enum kind {
        CREATE, DROP, USE, SHOW_TABLE
    };

    virtual kind getKind() const = 0;
};

// CREATE DATABASE <dbName>
class CreateDbStmt: public DbStmt {
private:
    Identifier* dbName;
public:
    explicit CreateDbStmt(Identifier* dbName): dbName(dbName) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Identifier* getDbName() const {
        return dbName;
    }
};

// DROP DATABASE <dbName>
class DropDbStmt: public DbStmt {
private:
    Identifier* dbName;
public:
    explicit DropDbStmt(Identifier* dbName): dbName(dbName) { }

    kind getKind() const override {
        return kind::DROP;
    }

    Identifier* getDbName() const {
        return dbName;
    }
};

// USE <dbName>
class UseDbStmt: public DbStmt {
private:
    Identifier* dbName;
public:
    explicit UseDbStmt(Identifier* dbName): dbName(dbName) { }

    kind getKind() const override {
        return kind::USE;
    }

    Identifier* getDbName() const {
        return dbName;
    }
};

// SHOW TABLES
class ShowDbStmt: public DbStmt {
public:
    ShowDbStmt() = default;

    kind getKind() const override {
        return kind::SHOW_TABLE;
    }
};

class TbStmt: public Stmt {
public:
    enum kind {
        CREATE, DROP, DESC, INSERT, DELETE, UPDATE, SELECT
    };

    virtual kind getKind() const = 0;
};

// CREATE TABLE <tbName> '('<fieldList>')'
class CreateTbStmt: public TbStmt {
private:
    Identifier* dbName;
    std::list<Field>* fieldList;

public:
    CreateTbStmt(Identifier* dbName, std::list<Field>* fieldList): dbName(dbName), fieldList(fieldList) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Identifier* getDbName() const {
        return dbName;
    }

    std::list<Field>* getFieldList() {
        return fieldList;
    }
};

// DROP TABLE <tbName>
class DropTbStmt: public TbStmt {
private:
    Identifier* dbName;

public:
    explicit DropTbStmt(Identifier* dbName): dbName(dbName) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Identifier* getDbName() const {
        return dbName;
    }
};

// DESC <tbName>
class DescTbStmt: public TbStmt {
private:
    Identifier* dbName;

public:
    explicit DescTbStmt(Identifier* dbName): dbName(dbName) { }

    kind getKind() const override {
        return kind::DESC;
    }

    Identifier* getDbName() const {
        return dbName;
    }
};

// INSERT INTO <tbName> VALUES <valueLists>
class InsertTbStmt: public TbStmt {
private:
    Identifier* dbName;
    std::list<Value>* valueList;

public:
    InsertTbStmt(Identifier* dbName, std::list<Value>* valueList): dbName(dbName), valueList(valueList) { }

    kind getKind() const override {
        return kind::CREATE;
    }

    Identifier* getDbName() const {
        return dbName;
    }

    std::list<Value>* getValueList() {
        return valueList;
    }
};

// DELETE FROM <tbName> WHERE <whereClause>
class DeleteTbStmt: public TbStmt {
private:
    Identifier* tbName;
    WhereClause* whereClause;

public:
    explicit DeleteTbStmt(Identifier* tbName, WhereClause* whereClause): tbName(tbName), whereClause(whereClause) { }

    Identifier* getTbName() {
        return tbName;
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
    Identifier* tbName;
    SetClause* setClause;
    WhereClause* whereClause;

public:
    explicit UpdateTbStmt(Identifier* tbName, SetClause* setClause, WhereClause* whereClause): tbName(tbName),
                                                                                               setClause(setClause),
                                                                                               whereClause(whereClause) { }

    Identifier* getTbName() {
        return tbName;
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
    std::list<Column>* selector; // 为null时表示*
    std::list<Identifier>* tableList;
    WhereClause* whereClause;

public:
    SelectTbStmt(std::list<Column>* selector, std::list<Identifier>* tableList, WhereClause* whereClause): selector(selector),
                                                                                                           tableList(tableList),
                                                                                                           whereClause(whereClause) { }

    kind getKind() const override {
        return kind::SELECT;
    }
};

class IdxStmt: public Stmt {
protected:
    Identifier* tbName;
    Identifier* colName;

public:
    enum kind {
        CREATE, DROP
    };

    IdxStmt(Identifier* tbName, Identifier* colName): tbName(tbName), colName(colName) { }

    Identifier* getTbName() {
        return tbName;
    }

    Identifier* getColName() {
        return colName;
    }

    virtual kind getKind() const = 0;
};

// <idxStmt>  := CREATE INDEX <tbName> '(' <colName> ')'
class CreateIdxStmt: public IdxStmt {
public:
    CreateIdxStmt(Identifier* tbName, Identifier* colName): IdxStmt(tbName, colName) { }

    kind getKind() const override {
        return kind::CREATE;
    }
};

// <idxStmt>  := DROP INDEX <tbName> '(' <colName> ')'
class DropIdxStmt: public IdxStmt {
public:
    DropIdxStmt(Identifier* tbName, Identifier* colName): IdxStmt(tbName, colName) { }

    kind getKind() const override {
        return kind::DROP;
    }
};

#endif //MYDB_TREE_H
