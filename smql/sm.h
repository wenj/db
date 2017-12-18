#include "../pf/redbase.h"
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../rm/rm.h"
#include "../ix/ix.h"

class AttrInfo;

struct RelInfo {
	char *relName;
	int attrNum;
	AttrInfo* attrInfos;
};

struct IndexInfo {
	char *relName;
	AttrInfo indexInfo;
};

// Used by SM_Manager::CreateTable
struct AttrInfo {
   char *attrName;           // 长度必须为MAXNAME
   AttrType attrType;            // Type of attribute
   int attrLength;          // Length of attribute
};

// Used by Printer class
struct DataAttrInfo {
   char relName[MAXNAME+1];  // Relation name
   char attrName[MAXNAME+1]; // Attribute name
   int offset;              // Offset of attribute 
   AttrType attrType;            // Type of attribute 
   int attrLength;          // Length of attribute
   int indexNo;             // Attribute index number
};


class SM_Manager {
private:
	static const std::string rootPath;
	std::string curPath;
	bool hasAttachedDb;
	IX_Manager ixManager;
	RM_Manager rmManager;
	RM_FileHandle indexHandle; // attach到dbindex上
	RM_FileHandle attrHandle; // attach到dbattr上

	bool HasDir(const std::string &path, const std::string &obj);
	bool HasFile(const std::string &path, const std::string &obj);

public:
	SM_Manager(IX_Manager &ixm, RM_Manager &rmm);  // Constructor
    ~SM_Manager();                                  // Destructor
	RC CreateDb(const char *dbName);
	RC DropDb(const char*dbName);
    RC UseDb(const char *dbName);
	RC ShowDb(const char *dbName);
    RC CloseDb(); 
    RC CreateTable(const char *relName, int attrCount, AttrInfo *attributes);
    RC DropTable(const char *relName);
	RC ShowTable(const char *relName);
    RC CreateIndex(const char *relName, const char *attrName);
    RC DropIndex(const char *relName, const char *attrName);
};

#define SM_DBHASEXIST (START_SM_ERR - 0)
#define SM_DBNOTEXIST (START_SM_ERR - 1)
#define SM_DBNOTOPEN (START_SM_ERR - 2)
#define SM_TABLEEXIST (START_SM_ERR - 3)
#define SM_TABLENOTEXIST (START_SM_ERR - 4)
#define SM_ATTRNAMENOTEXIST (START_SM_ERR - 5)
#define SM_INDXNOTEXIST (START_SM_ERR - 6)