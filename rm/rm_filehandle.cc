#include <cstring>
#include "rm.h"

RM_FileHandle::RM_FileHandle() : hasAttachedFile(false) {}

RM_FileHandle::RM_FileHandle(PF_FileHandle &pffh) : hasAttachedFile(true), pffh(pffh) {
	int rc;
	PF_PageHandle pageHandle;
	rc = pffh.GetFirstPage(pageHandle);
	if (rc < 0) {
		hasAttachedFile = false;
		return;
	}
	RM_FileHdr fileHeader;
	rc = GetFileHdr(pageHandle, fileHeader);
	if (rc < 0) {
		hasAttachedFile = false;
		return;
	}

	recordSize = fileHeader.recordSize;
	recordNum = (PF_PAGE_SIZE - sizeof(char)) / (recordSize + 1);
	pageHeaderSize = 
		(recordNum / sizeof(char) + (recordNum % sizeof(char) > 0)) * sizeof(char) 
		+ 3 * sizeof(int);

	rc = pffh.UnpinPage(0);
	if (rc < 0) {
		hasAttachedFile = false;
		return;
	}
}

RM_FileHandle::~RM_FileHandle() {}

bool RM_FileHandle::isValidSlot(const RM_PageHdr &pageHeader, const SlotNum slotNum) const {
	return pageHeader.slots[slotNum / sizeof(char)] & (1 << (slotNum % sizeof(char)));
}

// 不提供Unpin和MarkDirty
RC RM_FileHandle::AllocatePage(PF_PageHandle &pageHandle, PageNum &pageNum) {
	int rc;

	// 创建新页
	rc = pffh.AllocatePage(pageHandle);
	if (rc < 0) {
		return rc;
	}
	rc = pageHandle.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}

	// 获得首页
	PF_PageHandle firstPage;
	rc = pffh.GetFirstPage(firstPage);
	if (rc < 0) {
		return rc;
	}
	RM_FileHdr fileHeader;
	rc = GetFileHdr(firstPage, fileHeader);
	if (rc < 0) {
		return rc;
	}

	// 初始化Page Header
	RM_PageHdr pageHeader;
	pageHeader.nextFree = fileHeader.firstFree;
	InitPageHdr(pageHeader);
	SetPageHdr(pageHandle, pageHeader);

	// 更新FileHeader
	fileHeader.firstFree = pageNum;
	fileHeader.numPages++;
	rc = SetFileHdr(firstPage, fileHeader);
	if (rc < 0) {
		return rc;
	}
	if ((rc = pffh.MarkDirty(0)) || (rc = pffh.UnpinPage(0))) {
		return rc;
	}
	return 0;
}

RC RM_FileHandle::InsertRecToPage(PF_PageHandle &pageHandle, const char *pData, SlotNum &slotNum) {
	int rc;

	// 更新PageHeader
	RM_PageHdr pageHeader;
	rc = GetPageHdr(pageHandle, pageHeader);
	if (rc < 0) {
		return rc;
	}
	pageHeader.usedSlotNum++;
	pageHeader.freeSlotNum--;
	for (int i = 0; i < recordNum / sizeof(char) + (recordNum % sizeof(char) > 0); ++i) {
		if ((pageHeader.slots[i] & 0xff) != 0xff) {
			for (int j = 0; j < 8; ++j) {
				if ((pageHeader.slots[i] & (1 << j)) != (1 << j)) {
					pageHeader.slots[i] |= (1 << j);
					slotNum = (i << 3) + j;
					break;
				}
			}
			break;
		}
	}
	rc = SetPageHdr(pageHandle, pageHeader);
	if (rc < 0) {
		return rc;
	}

	// 插入记录
	char *pageData;
	rc = pageHandle.GetData(pageData);
	if (rc < 0) {
		return rc;
	}
	memcpy(pageData + pageHeaderSize + slotNum * recordSize, pData, recordSize);

	// MarkDirty & Unpin
	PageNum pageNum;
	rc = pageHandle.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	if ((rc = pffh.MarkDirty(pageNum)) || (rc = pffh.UnpinPage(pageNum))) {
		return rc;
	}

	// 更新首页
	if (pageHeader.freeSlotNum == 0) {
		PF_PageHandle firstPage;
		rc = pffh.GetFirstPage(firstPage);
		if (rc < 0) {
			return rc;
		}
		RM_FileHdr fileHeader;
		rc = GetFileHdr(firstPage, fileHeader);
		if (rc < 0) {
			return rc;
		}
		fileHeader.firstFree = pageHeader.nextFree;
		rc = SetFileHdr(firstPage, fileHeader);
		if (rc < 0) {
			return rc;
		}
		if ((rc = pffh.MarkDirty(0)) || (rc = pffh.UnpinPage(0))) {
			return rc;
		}
	}
	return 0;
}

RC RM_FileHandle::GetFileHdr(const PF_PageHandle &pageHandle, RM_FileHdr &fileHeader) const {
	int rc;
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(&fileHeader, pData, sizeof(RM_FileHdr));
	return 0;
}

RC RM_FileHandle::SetFileHdr(const PF_PageHandle &pageHandle, RM_FileHdr &fileHeader) {
	int rc;
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(pData, &fileHeader, sizeof(RM_FileHdr));
	return 0;
}

RC RM_FileHandle::GetPageHdr(const PF_PageHandle &pageHandle, RM_PageHdr &pageHeader) const {
	int rc;
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(&pageHeader, pData, pageHeaderSize);
	return 0;
}

RC RM_FileHandle::SetPageHdr(PF_PageHandle &pageHandle, RM_PageHdr &pageHeader) {
	int rc;
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(pData, &pageHeader, pageHeaderSize);
	return 0;
}

// 没有初始化nextFreePage
RC RM_FileHandle::InitPageHdr(RM_PageHdr &pageHeader) {
	pageHeader.usedSlotNum = 0;
	pageHeader.freeSlotNum = recordNum;
	pageHeader.slots = new char[recordNum / sizeof(char) + (recordNum % sizeof(char) > 0)];
	memset(pageHeader.slots, 0xff, sizeof(char) * (recordNum / sizeof(char) + (recordNum % sizeof(char) > 0)));
	return 0;
}

RC RM_FileHandle::GetThisPage(PageNum pageNum, PF_PageHandle &pfph) const {
	int rc;
	rc = pffh.GetThisPage(pageNum, pfph);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC RM_FileHandle::GetRecord(const PF_PageHandle &pfph, PageNum pageNum, SlotNum slotNum, RM_Record &rec) const {
	int rc;

	// 检查槽是否合法
	RM_PageHdr pageHdr;
	rc = GetPageHdr(pfph, pageHdr);
	if (rc < 0) {
		return rc;
	}
	if (!isValidSlot(pageHdr, slotNum)) {
		return RM_RECORDNOTEXIST;
	}

	// 读取记录
	char *pData;
	rc = pfph.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	RID rid(pageNum, slotNum);
	RM_Record record(pData + pageHeaderSize + slotNum * sizeof(recordSize), rid, recordSize);
	rec = record;
	return 0;
}

RC RM_FileHandle::GetNextRec(const RID &rid, RM_Record &rec) const {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	// 获取页编号和槽编号
	int rc;
	int pageNum, slotNum;
	int nextPageNum = -1, nextSlotNum = -1;
	rc = rid.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	rc = rid.GetSlotNum(slotNum);
	if (rc < 0) {
		return rc;
	}

	// 获取记录
	PF_PageHandle pageHandle;
	rc = GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	RM_PageHdr pageHeader;
	rc = GetPageHdr(pageHandle, pageHeader);
	if (rc < 0) {
		return rc;
	}

	// 查看该页该槽之后是否还有记录
	for (int i = slotNum + 1; i < recordNum; ++i) {
		if (pageHeader.slots[i / sizeof(char)] & (1 << (i % sizeof(char)))) {
			nextPageNum = pageNum;
			nextSlotNum = i;
			break;
		}
	}
	rc = pffh.UnpinPage(pageNum);
	if (rc < 0) {
		return rc;
	}

	// 查看之后的页上是否有记录
	if (nextPageNum != -1) {
		bool found = false;
		while (!found) {
			rc = pffh.GetNextPage(pageNum, pageHandle);
			if (rc == PF_EOF) {
				return RM_EOF;
			}
			rc = pageHandle.GetPageNum(pageNum);
			if (rc < 0) {
				return rc;
			}
			rc = GetPageHdr(pageHandle, pageHeader);
			if (rc < 0) {
				return rc;
			}
			for (int i = 0; i < recordNum; ++i) {
				if (pageHeader.slots[i / sizeof(char)] & (1 << (i % sizeof(char)))) {
					nextPageNum = pageNum;
					nextSlotNum = i;
					found = true;
					break;
				}
			}
			rc = pffh.UnpinPage(pageNum);
			if (rc < 0) {
				return rc;
			}
		}
		if (!found) {
			return RM_EOF;
		}
	}
	rc = GetRec(RID(nextPageNum, nextSlotNum), rec);
	return rc;
}

// Given a RID, return the record
RC RM_FileHandle::GetRec (const RID &rid, RM_Record &rec) const {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	// 获取页编号和槽编号
	int rc;
	int pageNum, slotNum;
	rc = rid.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	rc = rid.GetSlotNum(slotNum);
	if (rc < 0) {
		return rc;
	}

	// 获取记录
	PF_PageHandle pfph;
	rc = GetThisPage(pageNum, pfph);
	if (rc < 0) {
		return rc;
	}
	rc = GetRecord(pfph, pageNum, slotNum, rec);
	if (rc < 0) {
		return rc;
	}

	// Unpin第p页
	rc = pffh.UnpinPage(pageNum);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

// Insert a new record
RC RM_FileHandle::InsertRec (const char *pData, RID &rid) {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	// 获取File Header
	int rc;
	PF_PageHandle headerPage;
	rc = pffh.GetFirstPage(headerPage);
	if (rc < 0) {
		return rc;
	}
	RM_FileHdr fileHeader;
	rc = GetFileHdr(headerPage, fileHeader);

	PF_PageHandle insertPage;
	PageNum insertNum;
	SlotNum slotNum;
	// 如果没有新页
	if (fileHeader.firstFree == PF_EOF) {
		// 创建新页
		rc = AllocatePage(insertPage, insertNum);
		if (rc < 0) {
			return rc;
		}

		// 插入记录
		rc = InsertRecToPage(insertPage, pData, slotNum);
		if (rc < 0) {
			return rc;
		}
	} else {
		// 获得插入页
		insertNum = fileHeader.firstFree;
		rc = pffh.GetThisPage(insertNum, insertPage);
		if (rc < 0) {
			return rc;
		}

		// 插入记录
		rc = InsertRecToPage(insertPage, pData, slotNum);
		if (rc < 0) {
			return rc;
		}
	}
	RID insertRid(insertNum, slotNum);
	rid = insertRid;
	return 0;
}

// Delete a record
RC RM_FileHandle::DeleteRec (const RID &rid) {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	// 获得页编号和槽编号
	int rc;
	PageNum pageNum;
	SlotNum slotNum;
	rc = rid.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	rc = rid.GetSlotNum(slotNum);
	if (rc < 0) {
		return rc;
	}

	// 获得待删除页
	PF_PageHandle deletePage;
	rc = pffh.GetThisPage(pageNum, deletePage);
	if (rc < 0) {
		return rc;
	}

	// 更新Page Header
	RM_PageHdr pageHeader;
	rc = GetPageHdr(deletePage, pageHeader);
	if (rc < 0) {
		return rc;
	}
	if (!isValidSlot(pageHeader, slotNum)) {
		return RM_RECORDNOTEXIST;
	}
	pageHeader.freeSlotNum++;
	pageHeader.usedSlotNum--;
	pageHeader.slots[slotNum / sizeof(char)] ^= (1 << (slotNum % sizeof(char)));

	// 更新File Header
	if (pageHeader.freeSlotNum == 1) {
		PF_PageHandle firstPage;
		pffh.GetFirstPage(firstPage);
		RM_FileHdr fileHeader;
		GetFileHdr(firstPage, fileHeader);
		pageHeader.nextFree = fileHeader.firstFree;
		fileHeader.firstFree = pageNum;
		SetFileHdr(firstPage, fileHeader);

		if ((rc = pffh.MarkDirty(0)) || (rc = pffh.UnpinPage(0))) {
			return rc;
		}
	}

	SetPageHdr(deletePage, pageHeader);
	if ((rc = pffh.MarkDirty(pageNum)) || (rc = pffh.UnpinPage(pageNum))) {
		return rc;
	}
	return 0;
}

// Update a record
RC RM_FileHandle::UpdateRec (const RM_Record &rec) {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	int rc;

	RID rid;
	rc = rec.GetRid(rid);
	if (rc < 0) {
		return rc;
	}
	PageNum pageNum;
	SlotNum slotNum;
	rc = rid.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	rc = rid.GetSlotNum(slotNum);
	if (rc < 0) {
		return rc;
	}

	// 获得待更新页
	PF_PageHandle updatePage;
	rc = pffh.GetThisPage(pageNum, updatePage);
	if (rc < 0) {
		return rc;
	}

	// 检查记录是否存在
	RM_PageHdr pageHeader;
	rc = GetPageHdr(updatePage, pageHeader);
	if (rc < 0) {
		return rc;
	}
	if (!isValidSlot(pageHeader, slotNum)) {
		return RM_RECORDNOTEXIST;
	}

	// 更新记录
	char *pageData;
	rc = updatePage.GetData(pageData);
	if (rc < 0) {
		return rc;
	}
	char *pData;
	rc = rec.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	memcpy(pageData + pageHeaderSize + slotNum * recordSize, pData, recordSize);

	// MarkDirty & Unpin
	if ((rc = pffh.MarkDirty(pageNum)) || (rc = pffh.UnpinPage(pageNum))) {
		return rc;
	}
	return 0;
}

// Forces a page (along with any contents stored in this class)
// from the buffer pool to disk.  Default value forces all pages.
RC RM_FileHandle::ForcePages (PageNum pageNum) {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}

	int rc;
	if (pageNum == ALL_PAGES) {
		rc = pffh.ForcePages(pageNum);
		if (rc < 0) {
			return rc;
		}
		return 0;
	}

	PF_PageHandle pageHandle;
	rc = pffh.GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	rc = pffh.ForcePages(pageNum);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC RM_FileHandle::GetRecordSize(int &size) const {
	if (!hasAttachedFile) {
		return RM_NULLFILE;
	}
	size = recordSize;
	return 0;
}