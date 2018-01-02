#include <iostream>

#include "YYSTYPE.h"
#include "Tree.h"
#include "BFParse.h"
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
// #include "sm.h"

 PF_Manager pfm;
 RM_Manager rmm(pfm);
 IX_Manager ixm(pfm);
//SM_Manager smm(ixm, rmm);
//QL_Manager qlm(smm, ixm, rmm);

int main() {
    std::cout << "I am a database" << std::endl;
    Parse();
    /*
    char input[1000];
    while (true)
    {
        std::cout << "DATABASE<<";
        cout.flush();
        cin.getline(input, 1000);
        int val = BFParse::Parse(string(input));

        if (val < 0)
            break;
    }*/
    return 0;
}