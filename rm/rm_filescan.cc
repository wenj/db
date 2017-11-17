#include "rm.h"
#include <cstring>

RM_FileScan::RM_FileScan () : hasAttachedFile(false) {}

RM_FileScan::~RM_FileScan () {}

bool RM_FileScan::Comp(const RM_Record &record) {
	if (value == NULL) {
		return true;
	}

	char *pData;
	record.GetData(pData);
	char *compData = pData + attrOffset;
	switch (compOp) {
		case EQ_OP: {
			if (attrType == INT) {
				return *((int*)compData) == *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) == *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) == 0;
			}
		}
		case NE_OP: {
			if (attrType == INT) {
				return *((int*)compData) != *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) != *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) != 0;
			}
		}
		case LT_OP: {
			if (attrType == INT) {
				return *((int*)compData) < *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) < *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) < 0;
			}
		}
		case GT_OP: {
			if (attrType == INT) {
				return *((int*)compData) > *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) > *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) > 0;
			}
		}
		case LE_OP: {
			if (attrType == INT) {
				return *((int*)compData) <= *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) <= *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) <= 0;
			}
		}
		case GE_OP: {
			if (attrType == INT) {
				return *((int*)compData) >= *((int*)value);
			} else if (attrType == FLOAT) {
				return *((float*)compData) >= *((float*)value);
			} else if (attrType == STRING) {
				return strncmp(compData, (char*)value, attrLength) >= 0;
			}
		}
	}
}

// Note! pinHint还没有被使用
RC RM_FileScan::OpenScan (const RM_FileHandle &fileHandle, AttrType attrType, int attrLength, int attrOffset,
	CompOp compOp, void *value, ClientHint pinHint) {
	if (hasAttachedFile) {
		return RM_SCANHASOPEN;
	}

	// 检查扫描条件是否合法
	if (compOp != NO_OP && compOp != EQ_OP && compOp != NE_OP && compOp != LT_OP 
		&& compOp != GT_OP && compOp != LE_OP && compOp != GE_OP) {
		return RM_INVALIDSCAN;
	}
	if (attrType != INT && attrType != FLOAT && attrType != STRING) {
		return RM_INVALIDSCAN;
	}
	if ((attrType == INT && attrLength != sizeof(int)) 
		|| (attrType == FLOAT && attrLength != sizeof(float))
		|| (attrType == STRING && (attrLength == 0 || attrLength > MAXSTRINGLEN))) {
		return RM_INVALIDSCAN;
	}
	if (compOp == NO_OP && value != NULL) {
		return RM_INVALIDSCAN;
	}

	int rc;
	int recordSize;
	rc = fileHandle.GetRecordSize(recordSize);
	if (rc < 0) {
		return rc;
	}
	if (attrOffset + attrLength - 1 > recordSize) {
		return RM_INVALIDSCAN;
	}

	hasAttachedFile = true;
	this -> fileHandle = fileHandle;
	this -> attrType = attrType;
	this -> attrLength = attrLength;
	this -> attrOffset = attrOffset;
	this -> compOp = compOp;
	this -> value = value;
	this -> pinHint = pinHint;
	RID rid(0, PF_PAGE_SIZE + 4);
	curRid = rid;
	return 0;
}

RC RM_FileScan::GetNextRec(RM_Record &rec) {
	if (hasAttachedFile) {
		return RM_SCANNOTOPEN;
	}

	int rc;
	while (1) {
		RM_Record record;
		if ((rc = fileHandle.GetNextRec(curRid, record)) || (rc = record.GetRid(curRid))) {
			return rc;
		}
		PageNum pageNum;
		SlotNum slotNum;
		if ((rc = curRid.GetPageNum(pageNum) || (rc = curRid.GetSlotNum(slotNum)))) {
			return rc;
		}
		if (Comp(record)) {
			rec = record;
			return 0;
		}
	}
	return RM_UNKNOWNERROR;
}

RC RM_FileScan::CloseScan () {
	if (hasAttachedFile) {
		return RM_SCANNOTOPEN;
	}
	hasAttachedFile = false;
}