//
// Created by lenovo on 2018/1/2.
//

#ifndef MYDB_BFPARSE_H
#define MYDB_BFPARSE_H

#include <string>
#include <iostream>
#include <vector>
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
#include "sm.h"

using namespace std;

#define BFP_SYNERROR 2

class BFParse {
public:
    static int Parse(string str);
    static void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
};


#endif //MYDB_BFPARSE_H
