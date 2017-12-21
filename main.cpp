#include <iostream>

#include "YYSTYPE.h"
#include "Tree.h"
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
#include "sm.h"

PF_Manager pfm;
RM_Manager rmm(pfm);
IX_Manager ixm(pfm);
SM_Manager smm(ixm, rmm);
// QL_Manager qlm(smm, ixm, rmm);

int main() {
    std::cout << "我是一个数据库" << std::endl;
    Parse(&pfm, &smm);
    return 0;
}