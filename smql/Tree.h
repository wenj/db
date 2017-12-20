//
// Created by lenovo on 2017/12/20.
//

#ifndef MYDB_TREE_H
#define MYDB_TREE_H

#include <list>
#include <utility>

class Tree {

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

    /**
     * Field是什么呢？？
     */
    class Field: public Tree {
    protected:
        Identifier colName;
    public:
        enum kind {
            NORMAL, NOT_NULL, PRIMARY
        };

        explicit Field(const Identifier& colName): colName(colName) { }

        Identifier getColName() const {
            return colName;
        }

        virtual kind getKind() const = 0;
    };

    // <colName> <type>
    class NormalField: public Field {
    private:
        Type type;

    public:
        NormalField(const Identifier& colName, const Type& type): Field(colName), type(type) { }

        kind getKind() const override {
            return kind::NORMAL;
        }

        Type getType() const {
            return type;
        }
    };

    // <colName> <type> NOT NULL
    class NotNullField: public Field {
    private:
        Type type;

    public:
        NotNullField(const Identifier& colName, const Type& type): Field(colName), type(type) { }

        kind getKind() const override {
            return kind::NOT_NULL;
        }

        Type getType() const {
            return type;
        }
    };

    // PRIMARY KEY '(' <colName> ')'
    class PrimaryField: public Field {
    public:
        explicit PrimaryField(const Identifier& colName): Field(colName) { }

        kind getKind() const override {
            return kind::PRIMARY;
        }
    };

    class Stmt: public Tree {

    };

    // 只有一种指令：
    // SHOW DATABASES
    class SysStmt: public Stmt {
    public:
        SysStmt() {

        }
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
        Identifier dbName;
    public:
        explicit CreateDbStmt(const Identifier& dbName) {
            this->dbName = dbName;
        }

        kind getKind() const override {
            return kind::CREATE;
        }

        Identifier getDbName() const {
            return dbName;
        }
    };

    // DROP DATABASE <dbName>
    class DropDbStmt: public DbStmt {
    private:
        Identifier dbName;
    public:
        explicit DropDbStmt(const Identifier& dbName) {
            this->dbName = dbName;
        }

        kind getKind() const override {
            return kind::DROP;
        }

        Identifier getDbName() const {
            return dbName;
        }
    };

    // USE <dbName>
    class UseDbStmt: public DbStmt {
    private:
        Identifier dbName;
    public:
        explicit UseDbStmt(const Identifier& dbName) {
            this->dbName = dbName;
        }

        kind getKind() const override {
            return kind::USE;
        }

        Identifier getDbName() const {
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
        Identifier dbName;
        std::list<Field> fieldList;

    public:
        CreateTbStmt(const Identifier& dbName, std::list<Field> fieldList): dbName(dbName),
                                                                            fieldList(std::move(fieldList)) { }

        kind getKind() const override {
            return kind::CREATE;
        }

        Identifier getDbName() const {
            return dbName;
        }

        std::list<Field> getFieldList() {
            return fieldList;
        }
    };

    // DROP TABLE <tbName>
    class DropTbStmt: public TbStmt {
    private:
        Identifier dbName;

    public:
        explicit DropTbStmt(const Identifier& dbName): dbName(dbName) { }

        kind getKind() const override {
            return kind::CREATE;
        }

        Identifier getDbName() const {
            return dbName;
        }
    };
};


#endif //MYDB_TREE_H
