#include "rm_rid.h"

RID::RID() : pageNum(NULL_PAGE), slotNum(NULL_SLOT) {}
RID::RID(PageNum pageNum, SlotNum slotNum) : pageNum(pageNum), slotNum(slotNum) {}
RID::~RID() {}

RC RID::GetPageNum(PageNum &pageNum) const {
	pageNum = this -> pageNum;
	return 0;
}
RC RID::GetSlotNum(SlotNum &slotNum) const {
	slotNum = this -> slotNum;
	return 0;
}