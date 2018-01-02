//
// Created by lenovo on 2018/1/2.
//

#include <vector>
#include "BFParse.h"

void BFParse::SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int BFParse::Parse(string str) {
    cout << "Processing" << endl;
    cout << str << endl;
    cout.flush();

    if (!str.find(';'))
    {
        cout << "There is no comma in the input" << endl;
        return BFP_SYNERROR;
    }

    vector<string> stmtVector;
    SplitString(str, stmtVector, ";");

    // for (int i = 0)

    return 1;
}