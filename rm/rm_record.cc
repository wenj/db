#include <cstring>
#include "rm.h"
#include "rm_rid.h"

RM_Record::RM_Record () : hasData(false) {}

RM_Record::RM_Record(char *pData, RID rid, int recordSize) : hasData(true), pData(copy(pData, recordSize)), rid(rid), recordSize(recordSize) {}

RM_Record::~RM_Record() {
	delete[] pData;
}

char* RM_Record::copy(char *pData, int size) {
	char *temp = new char[size];
	std::memcpy(temp, pData, size);
	return temp;
}

// Return the data corresponding to the record.  Sets *pData to the
// record contents.
RC RM_Record::GetData(char *&pData) const {
	if (!hasData || this -> pData == NULL) {
		return RM_NULLRECORD;
	}
	pData = this -> pData;
	return 0;
}

// Return the RID associated with the record
RC RM_Record::GetRid (RID &rid) const {
	if (!hasData) {
		return RM_NULLRECORD;
	}
	rid = this -> rid;
	return 0;
}