//
// rm.h
//
//   Record Manager component interface
//
// This file does not include the interface for the RID class.  This is
// found in rm_rid.h
//

#ifndef RM_H
#define RM_H

// Please DO NOT include any files other than redbase.h and pf.h in this
// file.  When you submit your code, the test program will be compiled
// with your rm.h and your redbase.h, along with the standard pf.h that
// was given to you.  Your rm.h, your redbase.h, and the standard pf.h
// should therefore be self-contained (i.e., should not depend upon
// declarations in any other file).

// Do not change the following includes
#include "../pf/redbase.h"
#include "rm_rid.h"
#include "../pf/pf.h"

struct RM_PageHdr {
   int usedSlotNum;	
   int freeSlotNum;
   int nextFree;
   char *slots; 
};

struct RM_FileHdr {
   int firstFree;     // first free page in the linked list
   int numPages;      // # of pages in the file
   int recordSize;
};

//
// RM_Record: RM Record interface
//
class RM_Record {
private:
	char *pData;
	RID rid;
	int recordSize;
	bool hasData; // Records whether this object has record.

	char* copy(char *pData, int size);

public:
    RM_Record ();
	RM_Record(char *pData, RID rid, int recordSize);
    ~RM_Record();

    // Return the data corresponding to the record.  Sets *pData to the
    // record contents.
    RC GetData(char *&pData) const;

    // Return the RID associated with the record
    RC GetRid (RID &rid) const;
};

//
// RM_FileHandle: RM File interface
//
class RM_FileHandle {
	friend class RM_Manager;
protected:
	PF_FileHandle pffh;

private:
	bool hasAttachedFile;

	// 每页记录的数目 PageHeader的大小 每条记录的大小
	int recordNum, pageHeaderSize, recordSize;

	// 在Page Header中检查该槽是否有记录，若有记录返回True
	bool isValidSlot(const RM_PageHdr &pageHeader, const SlotNum slotNum) const;
	RC AllocatePage(PF_PageHandle &pageHandle, PageNum &pageNum);
	RC InsertRecToPage(PF_PageHandle &pageHandle, const char *pData, SlotNum &slotNum);
	RC InitPageHdr(RM_PageHdr &pageHeader);
	RC GetThisPage(PageNum pageNum, PF_PageHandle &pfph) const;
	RC GetValidSlot(const PF_PageHandle &pfph, SlotNum slotNum, RM_Record &rec) const;
	RC GetRecord(const PF_PageHandle &pfph, PageNum pageNum, SlotNum slotNum, RM_Record &rec) const;

public:
	RC GetFileHdr(const PF_PageHandle &pageHandle, RM_FileHdr &fileHeader) const;
	RC SetFileHdr(const PF_PageHandle &pageHandle, RM_FileHdr &fileHeader);
	RC GetPageHdr(const PF_PageHandle &pageHandle, RM_PageHdr &pageHeader) const;
	RC SetPageHdr(PF_PageHandle &pageHandle, RM_PageHdr &pageHeader);
	RC GetNextRec(const RID &rid, RM_Record &rec) const;
	RC GetRecordSize(int &size) const;

public:
    RM_FileHandle ();
	RM_FileHandle(PF_FileHandle &pffh);
    ~RM_FileHandle();

    // Given a RID, return the record
    RC GetRec     (const RID &rid, RM_Record &rec) const;

    RC InsertRec  (const char *pData, RID &rid);       // Insert a new record

    RC DeleteRec  (const RID &rid);                    // Delete a record
    RC UpdateRec  (const RM_Record &rec);              // Update a record

    // Forces a page (along with any contents stored in this class)
    // from the buffer pool to disk.  Default value forces all pages.
    RC ForcePages (PageNum pageNum = ALL_PAGES);
};

//
// RM_FileScan: condition-based scan of records in the file
//
class RM_FileScan {
private:
	bool hasAttachedFile;
	RM_FileHandle fileHandle;
	AttrType attrType;
	int attrLength;
	int attrOffset;
	CompOp compOp;
	void *value;
	ClientHint pinHint;
	RID curRid;

	bool Comp(const RM_Record &record);

public:
    RM_FileScan  ();
    ~RM_FileScan ();

    RC OpenScan  (const RM_FileHandle &fileHandle,
                  AttrType   attrType,
                  int        attrLength,
                  int        attrOffset,
                  CompOp     compOp,
                  void       *value,
                  ClientHint pinHint = NO_HINT); // Initialize a file scan
    RC GetNextRec(RM_Record &rec);               // Get next matching record
    RC CloseScan ();                             // Close the scan
};

//
// RM_Manager: provides RM file management
//
class RM_Manager {
private:
	PF_Manager pfm;

public:
    RM_Manager    (PF_Manager &pfm);
    ~RM_Manager   ();

    RC CreateFile (const char *fileName, int recordSize);
    RC DestroyFile(const char *fileName);
    RC OpenFile   (const char *fileName, RM_FileHandle &fileHandle);

    RC CloseFile  (RM_FileHandle &fileHandle);
};

//
// Print-error function
//
void RM_PrintError(RC rc);

#define RM_NULLRECORD (START_RM_ERR - 0)
#define RM_NULLFILE (START_RM_ERR - 1)
// #define RM_NULLRID (START_RM_ERR - 2)
#define RM_INVALIDSLOTNUM (START_RM_ERR - 3)
#define RM_RECORDNOTEXIST (START_RM_ERR - 4)
#define RM_SCANHASOPEN (START_RM_ERR - 5)
#define RM_SCANNOTOPEN (START_RM_ERR - 6)
#define RM_INVALIDSCAN (START_RM_ERR - 7)
#define RM_UNKNOWNERROR (START_RM_ERR - 8)
#define RM_SIZEEXCEED (START_RM_ERR - 9)
#define RM_BADSIZE (START_RM_ERR - 10)

#define RM_EOF (START_RM_WARN + 0)

#endif
