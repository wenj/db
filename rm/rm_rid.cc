#include "rm_rid.h"

RID::RID() : pageNum(NULL_PAGE), slotNum(NULL_SLOT) {}
RID::RID(PageNum pageNum, SlotNum slotNum) : pageNum(pageNum), slotNum(slotNum) {}
RID::~RID() {}

RC RID::GetPageNum(PageNum &pageNum) const {
	if (this -> pageNum == NULL_PAGE) {
		return RM_NULLRID;
	}
	pageNum = this -> pageNum;
	return 0;
}
RC RID::GetSlotNum(SlotNum &slotNum) const {
	if (this -> slotNum == NULL_SLOT) {
		return RM_NULLRID;
	}
	slotNum = this -> slotNum;
	return 0;
}