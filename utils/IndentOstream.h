//
// Created by lenovo on 2017/12/21.
//

#ifndef MYDB_INDENTOSTREAM_H
#define MYDB_INDENTOSTREAM_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IndentOstream {
private:
    static int indent;
    static string indent_str;
    static string tab;
    static string content;

public:
    static void init() {
        indent = 0;
        indent_str = "";
        tab = "    ";
    }

    template <typename T>
    static string toString(T val)
    {
        stringstream stream;
        stream << val;
        return stream.str();
    }

    static void incIndent() {
        indent++;
        indent_str += tab;
    }

    static void decIndent() {
        if (indent > 0) {
            indent--;
            indent_str = indent_str.substr(0, tab.size()*indent);
        }
    }

    static void write() {
        cout << content << endl;
        content = "";
        cout.flush();
    }

    static void write(const char* s) {
        cout << indent_str << content << s << endl;
        content = "";
        cout.flush();
    }

    template <typename T>
    static void write(const T& val)
    {
        stringstream stream;
        stream << val;
        cout << indent_str << content << stream.str() << endl;
        content = "";
        cout.flush();
    }

    static void writeAppend(const char* s) {
        content += s;
    }

    template <typename T>
    static void writeAppend(const T& val)
    {
        writeAppend(toString(val));
    }
};


#endif //MYDB_INDENTOSTREAM_H
