//
// rm_rid.h
//
//   The Record Id interface
//

#ifndef RM_RID_H
#define RM_RID_H

// We separate the interface of RID from the rest of RM because some
// components will require the use of RID but not the rest of RM.

#include "../pf/redbase.h"

#define RM_NULLRID (START_RM_ERR - 2) // Moves it from rm.h.

//
// PageNum: uniquely identifies a page in a file
//
typedef int PageNum;

//
// SlotNum: uniquely identifies a record in a page
//
typedef int SlotNum;

//
// RID: Record id interface
//
class RID {
private:
	static const int NULL_PAGE = -1;
	static const int NULL_SLOT = -1;

	int pageNum, slotNum;

public:
    RID();                                         // Default constructor
    RID(PageNum pageNum, SlotNum slotNum);
    ~RID();                                        // Destructor

    RC GetPageNum(PageNum &pageNum) const;         // Return page number
    RC GetSlotNum(SlotNum &slotNum) const;         // Return slot number

	bool operator<(const RID &t) const { 
        int pageNumT, slotNumT;
		t.GetPageNum(pageNumT);
		t.GetSlotNum(slotNumT);
		return (pageNum < pageNumT || (pageNum == pageNumT && slotNum < slotNumT));
    }

	bool operator==(const RID &t) const { 
        int pageNumT, slotNumT;
		t.GetPageNum(pageNumT);
		t.GetSlotNum(slotNumT);
		return (pageNum == pageNumT && slotNum == slotNumT);
    }

	bool operator!=(const RID &t) const { 
        int pageNumT, slotNumT;
		t.GetPageNum(pageNumT);
		t.GetSlotNum(slotNumT);
		return (pageNum != pageNumT || slotNum != slotNumT);
    }
};

#endif
