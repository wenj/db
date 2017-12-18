#ifndef IX_H
#define IX_H

#include "../pf/redbase.h"  // Please don't change these lines
#include "../rm/rm_rid.h"  // Please don't change these lines
#include "../pf/pf.h"

struct IX_FileHdr {
	AttrType attrType;
	int attrLength;
	int rootPage;
	int height;
};

struct IX_PageHdr {
	int num;
	int next; // 同一层的下一页编号
	int prev; // 同一层的上一页编号
};

struct IX_TreeNode {
	RID rid;
	RID maxRid; // 最大值记录的位置，为了便于处理两个记录的索引值相同的情况
	char *pData; // 该节点中的最大值
};

//
// IX_IndexHandle: IX Index File interface
//
class IX_IndexHandle {
private:
	bool hasAttachFile;
	bool headerChanged;
	PF_FileHandle *fileHandle;
	IX_FileHdr fileHeader;
	int nodeSize;
	int nodeNum;

	RC CopyNodeTo(const IX_TreeNode &treeNode, char *data);
	RC CopyNodeFrom(const char *data, IX_TreeNode &treeNode);
	RC CopyDataTo(const IX_TreeNode &treeNode, char *data);
	RC CopyDataFrom(const char *data, IX_TreeNode &treeNode);
	RC Comp(const IX_TreeNode &node1, const IX_TreeNode &node2);

private:
	RC AllocateNewTree(IX_TreeNode &treeNode);
	RC GetInsertRid(const int pageNum, const IX_TreeNode &treeNode, bool strict, RID &rid, int &nextPageNum);
	RC GetRid(const int &pageNum, const IX_TreeNode &treeNode, RID &rid, int &nextPageNum);
	RC Insert(const RID &rid, IX_TreeNode &treeNode, bool &split);
	RC InsertNode(IX_TreeNode &treeNode);
	RC GetTreeNode(const RID &rid, IX_TreeNode &treeNode);
	RC FindIndex(const IX_TreeNode &treeNode, RID *ridList, bool &hasFound);
	RC DeleteNode(const RID &rid, bool &needMerge);
	RC Merge(PF_PageHandle &pageHandle1, PF_PageHandle &pageHandle2);
	RC CheckMerge(const RID &rid, bool &needMerge);
	int CompValue(const void *data1, const void *data2);
	bool MeetRequirement(const IX_TreeNode &treeNode, const CompOp compOp, const void *value);
	RC GetFirstNode(RID &curIndexPos, IX_TreeNode &treeNode);
	RC SearchFirstNode(const CompOp compOp, const void *value, RID &curIndexPos, IX_TreeNode &treeNode);

public:
    IX_IndexHandle();
	IX_IndexHandle(PF_FileHandle *fileHandle);
    ~IX_IndexHandle();

    // Insert a new index entry
    RC InsertEntry(void *pData, const RID &rid);

    // Delete a new index entry
    RC DeleteEntry(void *pData, const RID &rid);

    // Force index files to disk
    RC ForcePages();
	RC GetNextEntry(CompOp compOp, void *value, RID &curIndexPos, RID &rid);
	RC CloseIndex();
};

//
// IX_IndexScan: condition-based scan of index entries
//
class IX_IndexScan {
private:
	bool hasAttachedFile;
	bool startScan; // 记录是否开始扫描
	IX_IndexHandle *indexHandle;
	CompOp compOp;
	void *value;
	ClientHint pinHint;
	RID curIndexPos; // 记录的是当前扫描的记录在树中的位置

public:
    IX_IndexScan();
    ~IX_IndexScan();

    // Open index scan
    RC OpenScan(const IX_IndexHandle &indexHandle,
                CompOp compOp,
                void *value,
                ClientHint  pinHint = NO_HINT);

    // Get the next matching entry return IX_EOF if no more matching
    // entries.
    RC GetNextEntry(RID &rid);

    // Close index scan
    RC CloseScan();
};

//
// IX_Manager: provides IX index file management
//
class IX_Manager {
private:
	PF_Manager &pfm;

public:
    IX_Manager(PF_Manager &pfm);
    ~IX_Manager();

    // Create a new Index
    RC CreateIndex(const char *fileName, int indexNo,
                   AttrType attrType, int attrLength);

    // Destroy and Index
    RC DestroyIndex(const char *fileName, int indexNo);

    // Open an Index
    RC OpenIndex(const char *fileName, int indexNo,
                 IX_IndexHandle &indexHandle);

    // Close an Index
    RC CloseIndex(IX_IndexHandle &indexHandle);
};

//void IX_PrintError(RC rc);

#define IX_INVALIDPAGE (START_IX_ERR - 0)
#define IX_DUPLICATEINDEX (START_IX_ERR - 1)
#define IX_NULLFILE (START_IX_ERR - 2)
#define IX_MERGEFAIL (START_IX_ERR - 3)
#define IX_DELETEERROR (START_IX_ERR - 4)
#define IX_INDEXNOTEXIST (START_IX_ERR - 5)
#define IX_FILEHASOPEN (START_IX_ERR - 6)
#define IX_INVALIDSCAN (START_IX_ERR - 7)
#define IX_SCANNOTOPEN (START_IX_ERR - 8)
#define IX_GETENTRYFAILED (START_IX_ERR - 9)

#define IX_NONEXTENTRY (START_IX_WARN + 0)

#endif