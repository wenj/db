#include "sm.h"
#include "stdafx.h"
#include "direct.h"
#include <io.h>
#include <vector>
#include <string>
#include <iostream>

const std::string SM_Manager::rootPath = "E:\\database\\";

SM_Manager::SM_Manager(IX_Manager &ixm, RM_Manager &rmm) : hasAttachedDb(false), ixManager(ixm), rmManager(rmm) {}

bool SM_Manager::HasDir(const std::string &path, const std::string &obj) {
	long hFile   =   0;
    struct _finddata_t fileinfo;
    std::string p;
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1)
    {
        do {
            if((fileinfo.attrib &  _A_SUBDIR)) {
				return true;   
            }
        } while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
	return false;
}

bool SM_Manager::HasFile(const std::string &path, const std::string &obj) {
	long hFile   =   0;
    struct _finddata_t fileinfo;
    std::string p;
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1)
    {
        do {
            if((fileinfo.attrib &  !_A_SUBDIR)) {
				return true;   
            }
        } while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
	return false;
}

SM_Manager::~SM_Manager() {
	hasAttachedDb = false;
}

RC SM_Manager::CreateDb(const char *dbName) {
	if (HasDir(rootPath, dbName)) {
		return SM_DBHASEXIST;
	}
	int rc;
	mkdir((rootPath + dbName).c_str());

	// 建立一张记录所有关系信息的表，名为dbattr
	rc = rmManager.CreateFile((rootPath + dbName + "\\dbattr").c_str(), MAXNAME + sizeof(int) + MAXATTRS * (MAXNAME + sizeof(AttrType) + sizeof(int)));
	if (rc < 0) {
		return rc;
	}

	// 建立一张记录所有索引信息的表，名为dbindex
	rc = rmManager.CreateFile((rootPath + dbName + "\\dbindex").c_str(), MAXNAME);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC SM_Manager::DropDb(const char*dbName) {
	if (!HasDir(rootPath, dbName)) {
		return SM_DBNOTEXIST;
	}
	rmdir((rootPath + dbName).c_str());
	return 0;
}

RC SM_Manager::UseDb(const char *dbName) {
	if (hasAttachedDb) {
		CloseDb();
	}
	int rc;
	curPath = rootPath + dbName + "\\";
	rc = rmManager.OpenFile((curPath + "dbattr").c_str(), attrHandle);
	if (rc < 0) {
		return rc;
	}
	rc = rmManager.OpenFile((curPath + "dbindex").c_str(), indexHandle);
	if (rc < 0) {
		return rc;
	}
	hasAttachedDb = true;
	return 0;
}

RC SM_Manager::ShowDb(const char *dbName) {
	// TODO 检查该文件是否已经打开
	// 依次输出dbattr中的每个文件名
	int rc;
	RM_FileHandle fileHandle;
	rc = rmManager.OpenFile((curPath + dbName + "\\dbattr").c_str(), fileHandle);
	if (rc < 0) {
		return rc;
	}
	RM_FileScan fileScan;
	rc = fileScan.OpenScan(fileHandle, STRING, MAXNAME, 0, NO_OP, NULL);
	if (rc < 0) {
		return rc;
	}
	while (1) {
		RM_Record record;
		fileScan.GetNextRec(record);
		RID rid;
		record.GetRid(rid);
		if (rid == RID(-1, -1)) {
			break;
		}
		char *data;
		record.GetData(data);
		char nameData[MAXNAME];
		memcpy(nameData, data, MAXNAME);
		std::cout << nameData << std::endl;
		delete[] nameData;
	}
	fileScan.CloseScan();
	return 0;
}

RC SM_Manager::CloseDb() {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	int rc;
	rc = rmManager.CloseFile(attrHandle);
	if (rc < 0) {
		return rc;
	}
	rc = rmManager.CloseFile(indexHandle);
	if (rc < 0) {
		return rc;
	}
	curPath = "";
	hasAttachedDb = false;
	return 0;
}

RC SM_Manager::CreateTable(const char *relName, int attrCount, AttrInfo *attributes) {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	if (HasFile(relName)) {
		return SM_TABLEEXIST;
	}
	int rc;
	int recordSize;
	for (int i = 0; i < attrCount; ++i) {
		recordSize += attributes[i].attrLength;
	}
	rc = rmManager.CreateFile((curPath + relName).c_str(), recordSize);
	if (rc < 0) {
		return rc;
	}
	// 构造要插入到dbattr中的数据
	char tableData[MAXNAME + sizeof(int) + MAXATTRS * (MAXNAME + sizeof(AttrType) + sizeof(int))];
	memset(tableData, '\0', MAXNAME);
	memcpy(tableData, relName, strlen(relName));
	memcpy(tableData + MAXNAME, &attrCount, sizeof(int));
	memcpy(tableData + MAXNAME + sizeof(int), attributes, attrCount * (MAXNAME + sizeof(AttrType) + sizeof(int)));
	RID rid;
	rc = attrHandle.InsertRec(tableData, rid);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC SM_Manager::DropTable(const char *relName) {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	if (!HasFile(curPath, relName)) {
		return SM_TABLENOTEXIST;
	}
	int rc;
	rc = rmManager.DestroyFile((curPath + relName).c_str());
	if (rc < 0) {
		return rc;
	}
	RM_FileScan fileScan;
	char fullName[MAXNAME];
	memset(fullName, '\0', MAXNAME);
	memcpy(fullName, relName, strlen(relName));
	rc = fileScan.OpenScan(attrHandle, STRING, MAXNAME, 0, EQ_OP, (void*)fullName);
	if (rc < 0) {
		return rc;
	}
	RM_Record record;
	rc = fileScan.GetNextRec(record);
	RID rid;
	record.GetRid(rid);
	rc = attrHandle.DeleteRec(rid);
	if (rc < 0) {
		return rc;
	}
	fileScan.CloseScan();
	return 0;
}

RC SM_Manager::ShowTable(const char *relName) {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	if (!HasFile(curPath, relName)) {
		return SM_TABLENOTEXIST;
	}
	int rc;
	RM_FileScan fileScan;
	char fullName[MAXNAME];
	memset(fullName, '\0', MAXNAME);
	memcpy(fullName, relName, strlen(relName));
	rc = fileScan.OpenScan(attrHandle, STRING, MAXNAME, 0, EQ_OP, (void*)fullName);
	if (rc < 0) {
		return rc;
	}
	RM_Record record;
	rc = fileScan.GetNextRec(record);
	// TODO:record中是该表在dbattr中的存储记录，然后接下来我该干啥？
	fileScan.CloseScan();
	return 0;
}

RC SM_Manager::CreateIndex(const char *relName, const char *attrName) {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	if (!HasFile(curPath, relName)) {
		return SM_TABLENOTEXIST;
	}
	int rc;

	// 在dbindex中记录索引表
	RM_FileScan fileScan;
	char fullName[MAXNAME];
	memset(fullName, '\0', MAXNAME);
	memcpy(fullName, relName, strlen(relName));
	rc = fileScan.OpenScan(attrHandle, STRING, MAXNAME, 0, EQ_OP, (void*)fullName);
	if (rc < 0) {
		return rc;
	}
	RM_Record record;
	rc = fileScan.GetNextRec(record);
	if (rc < 0) {
		return rc;
	}
	fileScan.CloseScan();
	char *data;
	record.GetData(data);
	RID rid;
	record.GetRid(rid);
	if (rid == RID(-1, -1)) {
		return SM_TABLENOTEXIST;
	}
	int attrNum;
	memcpy(&attrNum, data + MAXNAME, sizeof(int));
	AttrInfo *attrInfos = (AttrInfo*)(data + MAXNAME + sizeof(int));
	char fullAttrName[MAXNAME];
	memset(fullAttrName, '\0', MAXNAME);
	memcpy(fullAttrName, attrName, strlen(attrName));
	int pos = -1, attrOffset;
	for (int i = 0; i < attrNum; ++i) {
		attrOffset += attrInfos[i].attrLength;
		if (strcmp(attrInfos[i].attrName, fullAttrName, MAXNAME) == 0) {
			attrOffset -= attrInfos[i].attrLength;
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		return SM_ATTRNAMENOTEXIST;
	}
	
	// 创建索引文件
	rc = ixManager.CreateIndex(relName, pos, attrInfos[pos].attrType, attrInfos[pos].attrLength);
	if (rc < 0) {
		return rc;
	}

	// 插入表中已经存在的记录
	// 打开table，拿到每一条记录
	// 打开索引，插入每一条记录
	RM_FileHandle fileHandle;
	rc = rmManager.OpenFile((curPath + relName).c_str(), fileHandle);
	if (rc < 0) {
		return rc;
	}
	rc = fileScan.OpenScan(fileHandle, attrInfos[pos].attrType, attrInfos[i].attrLength, attrOffset, NO_OP, NULL);
	if (rc < 0) {
		return rc;
	}
	IX_IndexHandle indexHandle;
	rc = ixManager.OpenIndex((curPath + relName).c_str(), pos, indexHandle);
	if (rc < 0) {
		return rc;
	}
	while (1) {
		RM_Record record;
		fileScan.GetNextRec(record);
		if (rid == RID(-1, -1)) {
			break;
		}
		RID rid;
		char *data;
		record.GetRid(rid);
		if (rid == RID(-1, -1)) {
			break;
		}
		record.GetData(data);
		data += attrOffset;
		rc = indexHandle.InsertEntry((void*)data, rid);
		if (rc < 0) {
			return rc;
		}
	}
	if ((rc = ixManager.CloseIndex(indexHandle)) || (rc = fileScan.CloseScan())) {
		return rc;
	}
	return 0;
}

RC SM_Manager::DropIndex(const char *relName, const char *attrName) {
	if (!hasAttachedDb) {
		return SM_DBNOTOPEN;
	}
	if (!HasFile(curPath, relName)) {
		return SM_TABLENOTEXIST;
	}
	int rc;

	// 在dbindex中删除索引表
	RM_FileScan fileScan;
	char fullName[MAXNAME];
	memset(fullName, '\0', MAXNAME);
	memcpy(fullName, relName, strlen(relName));
	rc = fileScan.OpenScan(attrHandle, STRING, MAXNAME, 0, EQ_OP, (void*)fullName);
	if (rc < 0) {
		return rc;
	}
	RM_Record record;
	rc = fileScan.GetNextRec(record);
	if (rc < 0) {
		return rc;
	}
	fileScan.CloseScan();
	char *data;
	record.GetData(data);
	RID rid;
	record.GetRid(rid);
	if (rid == RID(-1, -1)) {
		return SM_TABLENOTEXIST;
	}
	int attrNum;
	memcpy(&attrNum, data + MAXNAME, sizeof(int));
	AttrInfo *attrInfos = (AttrInfo*)(data + MAXNAME + sizeof(int));
	char fullAttrName[MAXNAME];
	memset(fullAttrName, '\0', MAXNAME);
	memcpy(fullAttrName, attrName, strlen(attrName));
	int pos = -1, attrOffset;
	for (int i = 0; i < attrNum; ++i) {
		attrOffset += attrInfos[i].attrLength;
		if (strcmp(attrInfos[i].attrName, fullAttrName, MAXNAME) == 0) {
			attrOffset -= attrInfos[i].attrLength;
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		return SM_ATTRNAMENOTEXIST;
	}
	if (rc < 0) {
		return rc;
	}

	bool foundIndex = false;
	fileScan.OpenScan(indexHandle, STRING, MAXNAME, 0, EQ_OP, (void*)fullName);
	while (1) {
		RM_Record record;
		fileScan.GetNextRec(record);
		RID rid;
		record.GetRid(rid);
		if (rid == RID(-1, -1)) {
			break;
		}
		char *data;
		record.GetData(data);
		if (strcmp((IndexInfo*)(data + MAXNAME).attrName, fullAttrName, MAXNAME) == 0) {
			indexHandle.DeleteRec(rid);
		}
	}
	fileScan.CloseScan();
	if (!foundIndex) {
		return SM_INDXNOTEXIST;
	}

	// 删除索引文件
	rc = ixManager.DestroyIndex(relName, pos);
	if (rc < 0) {
		return rc;
	}
	return 0;
}