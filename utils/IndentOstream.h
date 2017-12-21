//
// Created by lenovo on 2017/12/21.
//

#ifndef MYDB_INDENTOSTREAM_H
#define MYDB_INDENTOSTREAM_H

#include <iostream>
#include <string>

using namespace std;

class IndentOstream {
private:
    static int indent;
    static string indent_str;
    static string tab;

public:
    static void init() {
        indent = 0;
        indent_str = "";
        tab = "    ";
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

    static void write(const char* s) {
        cout << indent_str << s << endl;
        cout.flush();
    }

    static void write(const string& s) {
        write(s.c_str());
    }
};


#endif //MYDB_INDENTOSTREAM_H
