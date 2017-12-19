#include "ix.h"
#include <cstring>
#include <string>
#include <stdlib.h>

IX_Manager::IX_Manager(PF_Manager &pfm) : pfm(pfm) {}
IX_Manager::~IX_Manager() {}

RC IX_Manager::CreateIndex(const char *fileName, int indexNo, AttrType attrType, int attrLength) {
	int rc;

	// 创建索引文件
	std::string indexFileName(fileName);
	indexFileName.append(".");
	char buffer[MAXNAME];
	itoa(indexNo, buffer, 10);
	indexFileName.append(buffer);
	rc = pfm.CreateFile(indexFileName.c_str());
	if (rc < 0) {
		return rc;
	}

	// 设置File Header
	PF_FileHandle fileHandle;
	rc = pfm.OpenFile(indexFileName.c_str(), fileHandle);
	if (rc < 0) {
		return rc;
	}
	PF_PageHandle pageHandle;
	rc = fileHandle.AllocatePage(pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *pData;
	rc = pageHandle.GetData(pData);
	IX_FileHdr fileHeader;
	memcpy(&fileHeader, pData, sizeof(IX_FileHdr));
	fileHeader.attrType = attrType;
	fileHeader.attrLength = attrLength;
	fileHeader.rootPage = -1;
	fileHeader.height = 0;
	memcpy(pData, &fileHeader, sizeof(IX_FileHdr));
	if ((rc = fileHandle.MarkDirty(0)) || (rc = fileHandle.UnpinPage(0))) {
		return rc;
	}
	return 0;
}

RC IX_Manager::DestroyIndex(const char *fileName, int indexNo) {
	int rc;

	// 打开索引文件
	std::string indexFileName(fileName);
	indexFileName.append(".");
	char buffer[MAXNAME];
	itoa(indexNo, buffer, 10);
	indexFileName.append(buffer);
	rc = pfm.DestroyFile(indexFileName.c_str());
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC IX_Manager::OpenIndex(const char *fileName, int indexNo, IX_IndexHandle &indexHandle) {
	int rc;

	// 打开索引文件
	std::string indexFileName(fileName);
	indexFileName.append(".");
	char buffer[MAXNAME];
	itoa(indexNo, buffer, 10);
	indexFileName.append(buffer);
	PF_FileHandle fileHandle;
	rc = pfm.OpenFile(indexFileName.c_str(), fileHandle);
	if (rc < 0) {
		return rc;
	}

	indexHandle = IX_IndexHandle(&fileHandle);
	return 0;
}

RC IX_Manager::CloseIndex(IX_IndexHandle &indexHandle) {
	int rc;
	rc = indexHandle.CloseIndex();
	if (rc < 0) {
		return rc;
	}
	return 0;
}