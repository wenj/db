#include "rm.h"
#include <cstring>

RM_Manager::RM_Manager(PF_Manager &pfm) : pfm(pfm) {}

RM_Manager::~RM_Manager() {}

RC RM_Manager::CreateFile(const char *fileName, int recordSize) {
	if (recordSize > PF_PAGE_SIZE - (int) sizeof(RM_FileHdr)) {
		return RM_SIZEEXCEED;
	}
	if (recordSize <= 0) {
		return RM_BADSIZE;
	}

	int rc;

	// 创建文件
	rc = pfm.CreateFile(fileName);
	if (rc < 0) {
		return rc;
	}

	// 创建File Header
	PF_FileHandle pffh;
	rc = pfm.OpenFile(fileName, pffh);
	if (rc < 0) {
		return rc;
	}
	PF_PageHandle pageHandle;
	rc = pffh.AllocatePage(pageHandle);
	if (rc < 0) {
		return rc;
	}
	RM_FileHdr fileHeader;
	fileHeader.firstFree = PF_EOF;
	fileHeader.numPages = 1;
	fileHeader.recordSize = recordSize;
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(pData, &fileHeader, sizeof(PF_FileHdr));

	if ((rc = pffh.MarkDirty(0)) || (rc = pffh.UnpinPage(0))) {
		return rc;
	}

	rc = pfm.CloseFile(pffh);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC RM_Manager::DestroyFile(const char *fileName) {
	int rc;
	rc = pfm.DestroyFile(fileName);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC RM_Manager::OpenFile(const char *fileName, RM_FileHandle &fileHandle) {
	int rc;
	PF_FileHandle pffh;
	rc = pfm.OpenFile(fileName, pffh);
	if (rc < 0) {
		return rc;
	}
	fileHandle = RM_FileHandle(pffh);
	return 0;
}

 // TODO:把FileHandle改为File Header在最后关闭文件时再更新保存
RC RM_Manager::CloseFile(RM_FileHandle &fileHandle) {
	int rc;
	rc = pfm.CloseFile(fileHandle.pffh);
	if (rc < 0) {
		return rc;
	}
	return 0;
}