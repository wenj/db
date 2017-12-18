#include "ix.h"

IX_IndexScan::IX_IndexScan() {}
IX_IndexScan::~IX_IndexScan() {}

RC IX_IndexScan::OpenScan(const IX_IndexHandle &indexHandle, CompOp compOp, void *value, ClientHint pinHint) {
	if (hasAttachedFile) {
		return IX_FILEHASOPEN;
	}

	if (compOp != NO_OP && compOp != EQ_OP && compOp != NE_OP && compOp != LT_OP 
		&& compOp != GT_OP && compOp != LE_OP && compOp != GE_OP) {
		return IX_INVALIDSCAN;
	}
	if (compOp == NO_OP && value != NULL) {
		return IX_INVALIDSCAN;
	}

	hasAttachedFile = true;
	this -> indexHandle = const_cast<IX_IndexHandle*>(&indexHandle);
	this -> compOp = compOp;
	this -> value = value;
	this -> pinHint = pinHint;
	startScan = false;
	curIndexPos = RID(-1, -1);
}

RC IX_IndexScan::GetNextEntry(RID &rid) {
	if (!hasAttachedFile) {
		return IX_SCANNOTOPEN;
	}
	int rc;
	if (!startScan || curIndexPos != RID(-1, -1)) {
		startScan = true;
		rc = indexHandle -> GetNextEntry(compOp, value, curIndexPos, rid);
		if (rc < 0) {
			return IX_GETENTRYFAILED;
		}
	}
	if (startScan && (rid == RID(-1, -1))) {
		return IX_NONEXTENTRY;
	}
}

RC IX_IndexScan::CloseScan() {
	if (!hasAttachedFile) {
		return IX_SCANNOTOPEN;
	}
	hasAttachedFile = false;
	startScan = false;
}