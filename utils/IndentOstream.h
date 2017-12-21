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

    static void write(const string& s) {
        write(s.c_str());
    }

    static void write(const int& i) {
        write(toString(i));
    }

    static void writeAppend(const char* s) {
        content += s;
    }

    static void writeAppend(const string& s) {
        writeAppend(s.c_str());
    }

    static void writeAppend(const int& i) {
        writeAppend(toString(i));
    }
};


#endif //MYDB_INDENTOSTREAM_H
