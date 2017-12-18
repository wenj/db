#include "ix.h"
#include <cstring>
#include <string>
#include <cstdlib>

IX_IndexHandle::IX_IndexHandle() : hasAttachFile(false) {}
IX_IndexHandle::~IX_IndexHandle() {
	if (hasAttachFile) {
		int rc;
		hasAttachFile = false;
		if (!headerChanged) {
			PF_PageHandle firstPageHandle;
			rc = fileHandle -> GetFirstPage(firstPageHandle);
			if (rc < 0) {
				return;
			}
			char *data;
			rc = firstPageHandle.GetData(data);
			if (rc < 0) {
				return;
			}
			memcpy(data, &fileHeader, sizeof(IX_FileHdr));
			int pageNum;
			rc = firstPageHandle.GetPageNum(pageNum);
			if (rc < 0) {
				return;
			}
			if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
				return;
			}
		}
	}
}

IX_IndexHandle::IX_IndexHandle(PF_FileHandle *fileHandle) : hasAttachFile(true), fileHandle(fileHandle), headerChanged(false) {
	int rc;
	PF_PageHandle pageHandle;
	rc = fileHandle -> GetFirstPage(pageHandle);
	if (rc < 0) {
		hasAttachFile = false;
		return;
	}
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		hasAttachFile = false;
		return;
	}
	memcpy(&fileHeader, pData, sizeof(IX_FileHdr));
	nodeSize = fileHeader.attrLength + sizeof(RID) + sizeof(RID);
	nodeNum = (PF_PAGE_SIZE - sizeof(IX_PageHdr)) / nodeSize;
}

RC IX_IndexHandle::CopyNodeTo(const IX_TreeNode &treeNode, char *data) {
	memcpy(data, &(treeNode.rid), sizeof(RID));
	memcpy(data + sizeof(RID), &(treeNode.maxRid), sizeof(RID));
	memcpy(data + 2 * sizeof(RID), treeNode.pData, fileHeader.attrLength);
}

RC IX_IndexHandle::CopyNodeFrom(const char *data, IX_TreeNode &treeNode) {
	treeNode.pData = new char[fileHeader.attrLength];
	memcpy(&(treeNode.rid), data, sizeof(RID));
	memcpy(&(treeNode.maxRid), data + sizeof(RID), sizeof(RID));
	memcpy(treeNode.pData, data + 2 * sizeof(RID), fileHeader.attrLength);
}

RC IX_IndexHandle::CopyDataTo(const IX_TreeNode &treeNode, char *data) {
	memcpy(data + sizeof(RID), &(treeNode.maxRid), sizeof(RID));
	memcpy(data + 2 * sizeof(RID), treeNode.pData, fileHeader.attrLength);
}

RC IX_IndexHandle::CopyDataFrom(const char *data, IX_TreeNode &treeNode) {
	treeNode.pData = new char[fileHeader.attrLength];
	memcpy(&(treeNode.maxRid), data + sizeof(RID), sizeof(RID));
	memcpy(treeNode.pData, data + 2 * sizeof(RID), fileHeader.attrLength);
}

// ���node1 < node2 �򷵻�-1��node1 > node2 �򷵻�1
// ����RID����ȣ���������TreeNode�������
RC IX_IndexHandle::Comp(const IX_TreeNode &node1, const IX_TreeNode &node2) {
	if (fileHeader.attrType == INT) {
		if (*((int*)node1.pData) - *((int*)node2.pData) != 0) {
			return *((int*)node1.pData) - *((int*)node2.pData);
		}
	} else if (fileHeader.attrType == FLOAT) {
		if (*((float*)node1.pData) - *((float*)node2.pData) != 0) {
			return *((float*)node1.pData) - *((float*)node2.pData);
		}
	} else if (fileHeader.attrType == STRING) {
		if (memcmp(node1.pData, node2.pData, fileHeader.attrLength) != 0) {
			return memcmp(node1.pData, node2.pData, fileHeader.attrLength);
		}
	}
	if (node1.maxRid < node2.maxRid) {
		return -1;
	} else if (node1.maxRid == node2.maxRid) {
		return 0;
	} else {
		return 1;
	}
}

// ���������ڵ�һ�β���������ʱ 
RC IX_IndexHandle::AllocateNewTree(IX_TreeNode &treeNode) {
	int rc;
	PF_PageHandle pageHandle;
	rc = fileHandle -> AllocatePage(pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr pageHeader;
	memcpy(&pageHeader, pData, sizeof(IX_PageHdr));
	pageHeader.num = 1;
	pageHeader.prev = -1;
	pageHeader.next = -1;
	memcpy(pData, &pageHeader, sizeof(IX_PageHdr));
	memcpy(pData + sizeof(IX_PageHdr), &treeNode, nodeSize);
	PageNum pageNum;
	rc = pageHandle.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
		return rc;
	}

	fileHeader.height++;
	fileHeader.rootPage = pageNum;
	headerChanged = true;
	return 0;
}

// ���������ĳһҳ�Ĳ���λ�ã������ڷ���ֵ�в۵�ǰ��
// @param pageNum ���ҵ�ҳ��
// @param treeNode ����/����ֵ
// @param strict ���������Ϊtrue�����ʾ�����������к�treeNode��ͬ��λ��
// @param rid ����λ��RID
// @param nextPageNum ��ҳҳ��
RC IX_IndexHandle::GetInsertRid(const int pageNum, const IX_TreeNode &treeNode, bool strict, RID &rid, int &nextPageNum) {
	// ���Page Header
	int rc;
	PF_PageHandle pageHandle;
	rc = fileHandle -> GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr pageHeader;
	memcpy(&pageHeader, pData, sizeof(IX_PageHdr));

	// �ҵ�����λ��
	if (pageHeader.num <= 0) {
		return IX_INVALIDPAGE;
	}
	for (int i = 0; i < pageHeader.num; ++i) {
		IX_TreeNode node; 
		memcpy(&node, pData + sizeof(IX_PageHdr) + i * nodeSize, nodeSize);
		int cmp = Comp(treeNode, node);
		if (strict && cmp == 0) {
			return IX_DUPLICATEINDEX;
		}
		if (cmp <= 0) {
			rid = RID(pageNum, i);
			rc = node.rid.GetPageNum(nextPageNum);
			if (rc < 0) {
				return rc;
			}
			rc = fileHandle -> UnpinPage(pageNum);
			if (rc < 0) {
				return rc;
			}
			return 0;
		}
	}
	// ������������нڵ�ֵ��������뵽���һ���ڵ�������У��������Ǹ��ڵ��pData
	IX_TreeNode node; 
	memcpy(&node, pData + sizeof(IX_PageHdr) + (pageHeader.num - 1) * nodeSize, nodeSize);
	rid = RID(pageNum, pageHeader.num - 1);
	rc = node.rid.GetPageNum(nextPageNum);
	memcpy(&node.pData, treeNode.pData, fileHeader.attrLength);
	node.maxRid = treeNode.maxRid;
	memcpy(pData + sizeof(IX_PageHdr) + (pageHeader.num - 1) * nodeSize, &node, nodeSize);
	if (rc < 0) {
		return rc;
	}

	// Markdown & Unpin��һҳ
	rc = fileHandle -> MarkDirty(pageNum);
	if (rc < 0) {
		return rc;
	}
	rc = fileHandle -> UnpinPage(pageNum);
	if (rc < 0) {
		return rc;
	}
	return 0;
}

// split��¼��ҳ�Ƿ���Ҫ���ѣ������Ҫ��Ҫ������������
RC IX_IndexHandle::Insert(const RID &rid, IX_TreeNode &treeNode, bool &split) {
	int rc;
	
	// ��ò���λ��
	int pageNum;
	rc = rid.GetPageNum(pageNum);
	if (rc < 0) {
		return rc;
	}
	PF_PageHandle pageHandle;
	rc = fileHandle -> GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *pData;
	rc = pageHandle.GetData(pData);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr pageHeader;
	memcpy(&pageHeader, pData, sizeof(IX_PageHdr));
	// �жϱ�ҳ�Ƿ��Ѿ����ˣ����û��ֱ�Ӳ��룬������Ҫ����
	if (pageHeader.num < nodeNum) {
		split = false;
		// ����Page Header
		++pageHeader.num;
		memcpy(pData, &pageHeader, sizeof(IX_PageHdr));
		// ��������
		int slotNum;
		rc = rid.GetSlotNum(slotNum);
		if (rc < 0) {
			return rc;
		}
		char *data = new char[(pageHeader.num - slotNum) * nodeSize];
		memcpy(data, pData + sizeof(IX_PageHdr) + slotNum * nodeSize, (pageHeader.num - slotNum) * nodeSize);
		memcpy(pData + sizeof(IX_PageHdr) + slotNum * nodeSize, &treeNode, nodeSize);
		memcpy(pData + sizeof(IX_PageHdr) + (slotNum + 1) * nodeSize, data, (pageHeader.num - slotNum) * nodeSize);
		delete[] data;
		if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
			return rc;
		}
	} else {
		split = true;
		int slotNum;
		rc = rid.GetSlotNum(slotNum);
		if (rc < 0) {
			return rc;
		}
		// �洢��������
		char *data = new char[(pageHeader.num + 1) * nodeSize];
		memcpy(data, pData + sizeof(IX_PageHdr), slotNum * nodeSize);
		memcpy(data + slotNum * nodeSize, &treeNode, nodeSize);
		memcpy(data + (slotNum + 1) * nodeSize, pData + sizeof(IX_PageHdr) + slotNum * nodeSize, (pageHeader.num - slotNum) * nodeSize);
		int splitPos = pageHeader.num / 2;

		// ���ѽڵ㡪��������ҳ��ǰһҳ������ҳ������Ŀ��ͬ��ǰҳ�Ⱥ�ҳ��1
		PF_PageHandle newPageHandle;
		rc = fileHandle -> AllocatePage(newPageHandle);
		if (rc < 0) {
			return rc;
		}
		char *newData;
		rc = newPageHandle.GetData(newData);
		if (rc < 0) {
			return rc;
		}
		IX_PageHdr newPageHeader;
		newPageHeader.num = splitPos + 1;
		newPageHeader.next = pageNum;
		newPageHeader.prev = pageHeader.prev;
		memcpy(newData, &newPageHeader, sizeof(IX_PageHdr));
		memcpy(newData + sizeof(IX_PageHdr), data, (splitPos + 1) * nodeSize);
		int newPageNum;
		rc = newPageHandle.GetPageNum(newPageNum);
		if (rc < 0) {
			delete[] data;
			return rc;
		}
		if ((rc = fileHandle -> MarkDirty(newPageNum)) || (rc = fileHandle -> UnpinPage(newPageNum))) {
			delete[] data;
			return rc;
		}

		// ����һҳ���ݸ���
		pageHeader.num = pageHeader.num  - splitPos;
		pageHeader.prev = newPageNum;
		memcpy(pData, &pageHeader, sizeof(IX_PageHdr));
		memcpy(pData + sizeof(IX_PageHdr), data + (splitPos + 1) * nodeSize, pageHeader.num * nodeSize);
		if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
			delete[] data;
			return rc;
		}

		// ���ý�Ҫ���뵽��ҳ�����ݣ�ǰһҳ��Ϣ��
		// �����ҳ�����ֵ��pData,maxRid��
		memcpy(&treeNode, pData + sizeof(IX_PageHdr) + (pageHeader.num - 1) * nodeSize, nodeSize);
		treeNode.rid = RID(newPageNum, -1);
		delete[] data;
	}
	return 0;
}

RC IX_IndexHandle::InsertNode(IX_TreeNode &treeNode) {
	// TODO: ��֤����û�кͲ���������ͬ��RID
	int rc;
	// ���ڼ�¼·���ϵĽڵ�λ�ã�PageNum��SlotNum��
	RID *ridList = new RID[fileHeader.height];
	int pageNum = fileHeader.rootPage;
	for (int i = 0; i < fileHeader.height; ++i) {
		int slotNum;
		rc = GetInsertRid(pageNum, treeNode, true, ridList[i], pageNum);
		if (rc < 0) {
			return rc;
			delete[] ridList;
		}
	}

	bool split = true;
	for (int i = fileHeader.height - 1; i >= 0 && split; --i) {
		Insert(ridList[i], treeNode, split);
	}

	// �����Ҫ���Ѹ��ڵ�
	if (split) {
		// ������ҳ
		PF_PageHandle pageHandle;
		rc = fileHandle -> AllocatePage(pageHandle);
		if (rc < 0) {
			delete[] ridList;
			return rc;
		}
		char *data;
		rc = pageHandle.GetData(data);
		if (rc < 0) {
			delete[] ridList;
			return rc;
		}
		IX_PageHdr pageHeader;
		pageHeader.num = 2;
		pageHeader.prev = -1;
		pageHeader.next = -1;
		memcpy(data, &pageHeader, sizeof(IX_PageHdr));
		
		// ���ԭʼ��ҳ��������Ϊ�µĸ�ҳ�ĵڶ�����ҳ 
		PF_PageHandle frontPageHandle;
		rc = fileHandle -> GetThisPage(fileHeader.rootPage, frontPageHandle);
		if (rc < 0) {
			delete[] ridList;
			return rc;
		}
		IX_TreeNode frontTreeNode;
		char *frontPageData;
		rc = frontPageHandle.GetData(frontPageData);
		if (rc < 0) {
			delete[] ridList;
			return rc;
		}
		IX_PageHdr frontPageHeader;
		memcpy(&frontPageHeader, frontPageData, sizeof(IX_PageHdr));
		memcpy(&frontTreeNode, frontPageData + sizeof(IX_PageHdr) + (frontPageHeader.num - 1) * nodeSize, nodeSize);
		frontTreeNode.rid = RID(fileHeader.rootPage, -1);
		memcpy(data + sizeof(IX_PageHdr) + nodeSize, &frontTreeNode, nodeSize);
		int frontPageNum;
		rc = frontPageHandle.GetPageNum(frontPageNum);
		if (rc < 0) {
			return rc;
		}
		rc = fileHandle -> UnpinPage(frontPageNum);
		if (rc < 0) {
			return rc;
		}

		// ����һ����ҳ��Ϣ���뵽�µĸ��ڵ㣨����ǰtreeNode�����ݣ�
		memcpy(data + sizeof(IX_PageHdr), &treeNode, nodeSize);

		// Unpin & markdirty
		int pageNum;
		rc = pageHandle.GetPageNum(pageNum);
		if (rc < 0) {
			delete[] ridList;
			return rc;
		}
		if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
			delete[] ridList;
			return rc;
		}

		// ����File Header
		fileHeader.rootPage = pageNum;
		fileHeader.height++;
		headerChanged = true;
	}
	delete[] ridList;
	return 0;
}

RC IX_IndexHandle::InsertEntry(void *pData, const RID &rid) {
	if (!hasAttachFile) {
		return IX_NULLFILE;
	}

	int rc;
	IX_TreeNode node;
	node.rid = rid;
	node.maxRid = rid;
	// ��ֹpData֮���޸�
	memcpy(node.pData, pData, fileHeader.attrLength);
	if (fileHeader.height == 0) {
		rc = AllocateNewTree(node);
	} else {
		rc = InsertNode(node);
	}
	if (rc < 0) {
		return rc;
	}
	return 0;
}

RC IX_IndexHandle::GetTreeNode(const RID &rid, IX_TreeNode &treeNode) {
	int rc;
	int pageNum, slotNum;
	if ((rc = rid.GetPageNum(pageNum)) || (rc = rid.GetSlotNum(slotNum))) {
		return rc;
	}
	PF_PageHandle pageHandle;
	rc = fileHandle -> GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *data;
	rc = pageHandle.GetData(data);
	if (rc < 0) {
		return rc;
	}
	memcpy(&treeNode, data + sizeof(IX_PageHdr) + slotNum * nodeSize, nodeSize);
	return 0;
}

// ��������(treeNode.pData, treeNode.rid)����·����¼��ridList�У�hasFound��¼�Ƿ���ҵ�
RC IX_IndexHandle::FindIndex(const IX_TreeNode &treeNode, RID *ridList, bool &hasFound) {
	int rc;
	int pageNum = fileHeader.rootPage;
	for (int i = 0; i < fileHeader.height; ++i) {
		int slotNum;
		rc = GetInsertRid(pageNum, treeNode, false, ridList[i], pageNum);
		if (rc < 0) {
			return rc;
		}
	}
	IX_TreeNode findNode;
	if (rc < 0) {
		GetTreeNode(ridList[fileHeader.height - 1], findNode);
		return rc;
	}
	hasFound = (Comp(findNode, treeNode) == 0);
	return 0;
}

// ɾ��ĳҳĳ�۵�����
RC IX_IndexHandle::DeleteNode(const RID &rid, bool &needMerge) {
	int rc;
	int pageNum, slotNum;
	if ((rc = rid.GetPageNum(pageNum)) || (rc = rid.GetSlotNum(slotNum))) {
		return rc;
	}
	PF_PageHandle pageHandle;
	rc = fileHandle -> GetThisPage(pageNum, pageHandle);
	if (rc < 0) {
		return rc;
	}
	char *data;
	rc = pageHandle.GetData(data);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr pageHeader;
	memcpy(&pageHeader, data, sizeof(IX_PageHdr));
	// ��ɾ���ۺ����������ǰƽ��
	char *tmp;
	memcpy(tmp, data + sizeof(IX_PageHdr) + (slotNum + 1) * nodeSize, (pageHeader.num - slotNum - 1) * nodeSize);
	memcpy(data + sizeof(IX_PageHdr) + slotNum * nodeSize, tmp, (pageHeader.num - slotNum - 1) * nodeSize);
	// ����PageHeader
	pageHeader.num--;
	memcpy(data, &pageHeader, sizeof(IX_PageHdr));
	if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
		return rc;
	}
	needMerge = (pageHeader.num <= nodeNum / 2);
	return 0;
}

// ����ҳ�ϲ�����һҳȥ������Unpin����ҳ�棩
RC IX_IndexHandle::Merge(PF_PageHandle &pageHandle1, PF_PageHandle &pageHandle2) {
	int rc;
	int pageNum1, pageNum2;
	if ((rc = pageHandle1.GetPageNum(pageNum1)) || (rc = pageHandle2.GetPageNum(pageNum2))) {
		return rc;
	}
	char *data1, *data2;
	if ((rc = pageHandle1.GetData(data1)) || (rc = pageHandle2.GetData(data2))) {
		return rc;
	}
	IX_PageHdr pageHeader1, pageHeader2;
	memcpy(&pageHeader1, data1, sizeof(IX_PageHdr));
	memcpy(&pageHeader2, data2, sizeof(IX_PageHdr));
	if (pageHeader1.num + pageHeader2.num > nodeNum) {
		return IX_MERGEFAIL;
	}
	char *data = new char[(pageHeader1.num + pageHeader2.num) * nodeSize];
	memcpy(data, data1 + sizeof(IX_PageHdr), nodeSize * pageHeader1.num);
	memcpy(data + nodeSize * pageHeader1.num, data2 + sizeof(IX_PageHdr), nodeSize * pageHeader2.num);
	pageHeader2.num += pageHeader1.num;
	pageHeader2.prev = pageHeader1.prev;
	memcpy(data2, &pageHeader2, sizeof(IX_PageHdr));
	memcpy(data2 + sizeof(IX_PageHdr), data, pageHeader2.num * nodeSize);

	if ((rc = fileHandle -> DisposePage(pageNum1)) || (rc = fileHandle -> MarkDirty(pageNum2)) || (rc = fileHandle -> UnpinPage(pageNum2))) {
		return rc;
	}
	delete[] data;
	return 0;
}

RC IX_IndexHandle::CheckMerge(const RID &rid, bool &needMerge) {
	int rc;
	// ��ø�ҳ�ò�
	int fatherPageNum, fatherSlotNum;
	if ((rc = rid.GetPageNum(fatherPageNum)) || (rc = rid.GetSlotNum(fatherSlotNum))) {
		return rc;
	}
	PF_PageHandle fatherPageHandle;
	rc = fileHandle -> GetThisPage(fatherPageNum, fatherPageHandle);
	if (rc < 0) {
		return rc;
	}
	char *fatherData;
	rc = fatherPageHandle.GetData(fatherData);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr fatherPageHeader;
	memcpy(&fatherPageHeader, fatherData, sizeof(IX_TreeNode));
	IX_TreeNode fatherNode;
	CopyNodeFrom(fatherData + sizeof(IX_PageHdr) + fatherSlotNum * nodeSize, fatherNode);

	// ��ø�TreeNodeָ���ҳ��Ϣ
	int childPageNum;
	rc = fatherNode.rid.GetPageNum(childPageNum);
	if (rc < 0) {
		return rc;
	}
	PF_PageHandle childPageHandle;
	rc = fileHandle -> GetThisPage(childPageNum, childPageHandle);
	if (rc < 0) {
		return rc;
	}
	char *childData;
	rc = childPageHandle.GetData(childData);
	if (rc < 0) {
		return rc;
	}
	IX_PageHdr childPageHeader;
	memcpy(&childPageHeader, childData, sizeof(IX_PageHdr));
	

	if (fatherSlotNum > 0) {
		IX_TreeNode fatherPrevNode;
		CopyNodeFrom(fatherData + sizeof(IX_PageHdr) + (fatherSlotNum - 1) * nodeSize, fatherPrevNode);
		int childPrevPageNum;
		rc = fatherPrevNode.rid.GetPageNum(childPrevPageNum);
		if (rc < 0) {
			return rc;
		}
		PF_PageHandle childPrevPageHandle;
		rc = fileHandle -> GetThisPage(childPrevPageNum, childPrevPageHandle);
		if (rc < 0) {
			return rc;
		}
		char *childPrevData;
		rc = childPrevPageHandle.GetData(childPrevData);
		if (rc < 0) {
			return rc;
		}
		IX_PageHdr childPrevPageHeader;
		memcpy(&childPrevPageHeader, childPrevData, sizeof(IX_PageHdr));
		// �ж�ǰһҳ�Ƿ����ת��һ������
		if (childPrevPageHeader.num > (nodeNum + 1) / 2) {
			IX_TreeNode childPrevDelNode;
			CopyNodeFrom(childPrevData + sizeof(IX_PageHdr) + (childPrevPageHeader.num - 1) * nodeSize, childPrevDelNode);
			IX_TreeNode childPrevLastNode;
			CopyNodeFrom(childPrevData + sizeof(IX_PageHdr) + (childPrevPageHeader.num - 2) * nodeSize, childPrevLastNode);
		
			bool tempBool;
			// ɾ��ǰһҳ���һ��node
			CopyDataTo(childPrevLastNode, fatherData + sizeof(IX_PageHdr) + (fatherSlotNum - 1) * nodeSize);
			rc = fileHandle -> UnpinPage(childPrevPageNum);
			if (rc < 0) {
				return rc;
			}
			rc = DeleteNode(RID(childPrevPageNum, childPrevPageHeader.num - 1), tempBool);
			if (rc < 0) {
				return rc;
			}
			if (tempBool) {
				return IX_DELETEERROR;
			}

			// ��ӵ�child page�ĵ�һ��node
			if (childPageHeader.num == 0) {
				CopyDataTo(childPrevDelNode, fatherData + sizeof(IX_PageHdr) + fatherSlotNum * nodeSize);
			}
			rc = fileHandle -> UnpinPage(childPageNum);
			if (rc < 0) {
				return rc;
			}
			rc = Insert(RID(childPageNum, 0), childPrevDelNode, tempBool);
			if (rc < 0) {
				return rc;
			} 
			if (tempBool) {
				return IX_DELETEERROR;
			}
		} else {
			// ��child prev page��child page�ϲ�
			rc = Merge(childPrevPageHandle, childPageHandle);
			if (rc < 0) {
				return rc;
			}
			rc = fileHandle -> UnpinPage(fatherPageNum);
			if (rc < 0) {
				return rc;
			}
			return DeleteNode(RID(fatherPageNum, fatherSlotNum - 1), needMerge);
		}
	} else if (fatherSlotNum < fatherPageHeader.num - 1) {
		IX_TreeNode fatherNextNode;
		CopyNodeFrom(fatherData + sizeof(IX_PageHdr) + (fatherSlotNum + 1) * nodeSize, fatherNextNode);
		int childNextPageNum;
		rc = fatherNextNode.rid.GetPageNum(childNextPageNum);
		if (rc < 0) {
			return rc;
		}
		PF_PageHandle childNextPageHandle;
		rc = fileHandle -> GetThisPage(childNextPageNum, childNextPageHandle);
		if (rc < 0) {
			return rc;
		}
		char *childNextData;
		rc = childNextPageHandle.GetData(childNextData);
		if (rc < 0) {
			return rc;
		}
		IX_PageHdr childNextPageHeader;
		memcpy(&childNextPageHeader, childNextData, sizeof(IX_PageHdr));
		// �жϺ�һҳ�Ƿ����ת��һ������
		if (childNextPageHeader.num > (nodeNum + 1) / 2) {
			IX_TreeNode childNextDelNode;
			CopyNodeFrom(childNextData + sizeof(IX_PageHdr), childNextDelNode);
			
			bool tempBool;
			// ɾ����һҳ��һ��node
			rc = fileHandle -> UnpinPage(childNextPageNum);
			if (rc < 0) {
				return rc;
			}
			rc = DeleteNode(RID(childNextPageNum, 0), tempBool);
			if (rc < 0) {
				return rc;
			}
			if (tempBool) {
				return IX_DELETEERROR;
			}

			// ��ӵ�child page�����һ��node
			CopyDataTo(childNextDelNode, fatherData + sizeof(IX_PageHdr) + fatherSlotNum * nodeSize); // ����fatherNode fatherSlotNum�۵����ֵ
			rc = fileHandle -> UnpinPage(childPageNum);
			if (rc < 0) {
				return rc;
			}
			rc = Insert(RID(childPageNum, childPageHeader.num), childNextDelNode, tempBool);
			if (rc < 0) {
				return rc;
			} 
			if (tempBool) {
				return IX_DELETEERROR;
			}
		} else {
			// ��child next page��child page�ϲ�
			rc = Merge(childPageHandle, childNextPageHandle);
			if (rc < 0) {
				return rc;
			}
			rc = fileHandle -> UnpinPage(fatherPageNum);
			if (rc < 0) {
				return rc;
			}
			return DeleteNode(RID(fatherPageNum, fatherSlotNum), needMerge);
		}
	}
	if ((rc = fileHandle -> MarkDirty(fatherPageNum)) || (rc = fileHandle -> UnpinPage(fatherPageNum))) {
		return rc;
	}
	needMerge = false;
	return 0;
}

RC IX_IndexHandle::DeleteEntry(void *pData, const RID &rid) {
	if (!hasAttachFile) {
		return IX_NULLFILE;
	}
	if (fileHeader.rootPage == -1) {
		return IX_INDEXNOTEXIST;
	}
	int rc;

	// �ҵ��Ӹ���Ҷ�ӵ�·��
	IX_TreeNode treeNode;
	treeNode.rid = rid;
	treeNode.maxRid = rid;
	memcpy(treeNode.pData, pData, sizeof(fileHeader.attrLength));
	// �洢����;����ÿһҳ�Ͷ�Ӧ�Ĳ�
	RID *ridList = new RID[fileHeader.height];
	bool hasFound;
	rc = FindIndex(treeNode, ridList, hasFound);
	if (rc < 0) {
		return rc;
	}
	if (!hasFound) {
		return IX_INDEXNOTEXIST;
	}

	// �ڵ��mergeֻ���ܷ�����·����
	// ����ɾ����Ҷ�ڵ������
	bool needMerge = true; // ��¼�ò�ڵ��Ƿ�merge������û�У����ϲ㶼����Ҫ
	rc = DeleteNode(ridList[fileHeader.height - 1], needMerge);
	if (rc < 0) {
		return rc;
	}
	// Ȼ����µ���ɨ�����е������ж��Ƿ���Ҫmerge
	for (int i = fileHeader.height - 2; i >= 0 && needMerge; --i) {
		rc = CheckMerge(ridList[i], needMerge);
		if (rc < 0) {
			return rc;
		}
	}
	// ���needMerge��Ϊtrue����ʾ���ڵ�Ҳ�����˱仯������Ҫ�鿴:������ֻʣһ����¼�������߶�-1;�������޼�¼�����Ϊ-1
	if (needMerge) {
		PF_PageHandle rootPageHandle;
		rc = fileHandle -> GetThisPage(fileHeader.rootPage, rootPageHandle);
		if (rc < 0) {
			return rc;
		}
		char* rootData;
		rc = rootPageHandle.GetData(rootData);
		if (rc < 0) {
			return rc;
		}
		IX_PageHdr rootPageHeader;
		memcpy(&rootPageHeader, rootData, sizeof(IX_PageHdr));
		if (rootPageHeader.num == 0) {
			rc = fileHandle -> DisposePage(fileHeader.rootPage);
			fileHeader.height--;
			fileHeader.rootPage = -1;
			headerChanged = true;
		} else if (rootPageHeader.num == 1) {
			IX_TreeNode treeNode;
			CopyNodeFrom(rootData + sizeof(IX_PageHdr), treeNode);
			rc = treeNode.rid.GetPageNum(fileHeader.rootPage);
			if (rc < 0) {
				return rc;
			}
			fileHeader.height--;
			headerChanged = true;
		}
	}
	return 0;
}

RC IX_IndexHandle::ForcePages() {
	if (!hasAttachFile) {
		return IX_NULLFILE;
	}
	return fileHandle -> ForcePages(ALL_PAGES);
}

RC IX_IndexHandle::CloseIndex() {
	if (!hasAttachFile) {
		return IX_NULLFILE;
	}
	int rc;
	hasAttachFile = false;
	if (!headerChanged) {
		PF_PageHandle firstPageHandle;
		rc = fileHandle -> GetFirstPage(firstPageHandle);
		if (rc < 0) {
			return rc;
		}
		char *data;
		rc = firstPageHandle.GetData(data);
		if (rc < 0) {
			return rc;
		}
		memcpy(data, &fileHeader, sizeof(IX_FileHdr));
		int pageNum;
		rc = firstPageHandle.GetPageNum(pageNum);
		if (rc < 0) {
			return rc;
		}
		if ((rc = fileHandle -> MarkDirty(pageNum)) || (rc = fileHandle -> UnpinPage(pageNum))) {
			return rc;
		}
	}
	return 0;
}

int IX_IndexHandle::CompValue(const void *data1, const void *data2) {
	if (fileHeader.attrType == INT) {
		return *((int*)data1) - *((int*)data2);
	} else if (fileHeader.attrType == FLOAT) {
		return *((float*)data1) - *((float*)data2);
	} else if (fileHeader.attrType == STRING) {
		return memcmp((char*)data1, (char*)data2, fileHeader.attrLength);
	}
}

bool IX_IndexHandle::MeetRequirement(const IX_TreeNode &treeNode, const CompOp compOp, const void *value) {
	if (compOp == LE_OP && CompValue((void*)treeNode.pData, value) <= 0) {
		return true;
	}
	if (compOp == LT_OP && CompValue((void*)treeNode.pData, value) < 0) {
		return true;
	}
	if (compOp == NO_OP) {
		return true;
	}
	if (compOp == NE_OP && CompValue((void*)treeNode.pData, value) != 0) {
		return true;
	}
	if (compOp == GT_OP && CompValue((void*)treeNode.pData, value) > 0) {
		return true;
	}
	if (compOp == GE_OP && CompValue((void*)treeNode.pData, value) >= 0) {
		return true;
	}
	if (compOp == EQ_OP && CompValue((void*)treeNode.pData, value) == 0) {
		return true;
	}
}

RC IX_IndexHandle::GetFirstNode(RID &curIndexPos, IX_TreeNode &treeNode) {
	if (fileHeader.height == 0) {
		curIndexPos = RID(-1, -1);
		return 0;
	}
	int pageNum = fileHeader.rootPage;
	for (int i = 0; i < fileHeader.height - 1; ++i) {
		PF_PageHandle pageHandle;
		fileHandle -> GetThisPage(pageNum, pageHandle);
		char *data;
		pageHandle.GetData(data);
		IX_TreeNode tempNode;
		CopyDataFrom(data + sizeof(IX_PageHdr), tempNode);
		fileHandle -> UnpinPage(pageNum);
		tempNode.rid.GetPageNum(pageNum);
	}
	PF_PageHandle pageHandle;
	fileHandle -> GetThisPage(pageNum, pageHandle);
	char *data;
	pageHandle.GetData(data);
	CopyDataFrom(data + sizeof(IX_PageHdr), treeNode);
	curIndexPos = RID(pageNum, 0);
	return 0;
}

RC IX_IndexHandle::SearchFirstNode(const CompOp compOp, const void *value, RID &curIndexPos, IX_TreeNode &treeNode) {
	if (fileHeader.height == 0) {
		curIndexPos = RID(-1, -1);
		return 0;
	}
	int pageNum = fileHeader.rootPage;
	for (int i = 0; i < fileHeader.height - 1; ++i) {
		PF_PageHandle pageHandle;
		fileHandle -> GetThisPage(pageNum, pageHandle);
		char *data;
		pageHandle.GetData(data);
		IX_PageHdr pageHeader;
		memcpy(&pageHeader, data, sizeof(IX_PageHdr));
		bool found = false;
		for (int j = 0; j < pageHeader.num; ++j) {
			IX_TreeNode tempNode;
			CopyDataFrom(data + sizeof(IX_PageHdr) + j * nodeSize, tempNode);
			if (MeetRequirement(tempNode, compOp, value)) {
				fileHandle -> UnpinPage(pageNum);
				tempNode.rid.GetPageNum(pageNum);
				found = true;
				break;
			}
		}
		if (!found) {
			fileHandle -> UnpinPage(pageNum);
			curIndexPos = RID(-1, -1);
			return 0;
		}
	}
	PF_PageHandle pageHandle;
	fileHandle -> GetThisPage(pageNum, pageHandle);
	char *data;
	pageHandle.GetData(data);
	IX_PageHdr pageHeader;
	memcpy(&pageHeader, data, sizeof(IX_PageHdr));
	bool found = false;
	RID rid;
	for (int i = 0; i < pageHeader.num; ++i) {
		IX_TreeNode tempNode;
		CopyDataFrom(data + sizeof(IX_PageHdr) + i * nodeSize, tempNode);
		if (MeetRequirement(tempNode, compOp, value)) {
			rid = tempNode.rid;
			CopyDataFrom(data + sizeof(IX_PageHdr) + i * nodeSize, treeNode);
			fileHandle -> UnpinPage(pageNum);
			return 0;
		}
	}
	rid = RID(-1, -1);
	return 0;
}

// NO_OP����ͷ��ʼɨ�����λ��ÿһ��treeNode������ľ���������
// LE_OP��LT_OP����ͷ��ʼɨ�����λ��ÿһ��treeNode�������õ����treeNode��������������������һ��
// NE_OP����ͷ��ʼɨ�����λ��ÿһ��treeNode�������õ����treeNode����������������������ɨ��
// GE_OP��GT_OP�������в��ҵ���һ�����������ģ������ľ���������
RC IX_IndexHandle::GetNextEntry(CompOp compOp, void *value, RID &curIndexPos, RID &rid) {
	int rc;
	if (curIndexPos == RID(-1, -1)) {
		IX_TreeNode treeNode;
		if (compOp == NO_OP || compOp == NE_OP || compOp == LE_OP || compOp == LT_OP) {
			rc = GetFirstNode(curIndexPos, treeNode);
			if (rc < 0) {
				return rc;
			}
		} else {
			rc = SearchFirstNode(compOp, value, curIndexPos, treeNode);
			if (rc < 0) {
				return rc;
			}
		}
		if (curIndexPos == RID(-1, -1)) {
			rid = RID(-1, -1);
			return 0;
		}
		if (MeetRequirement(treeNode, compOp, value)) {
			rid = treeNode.rid;
			return 0;
		} else {
			if (compOp != NE_OP) {
				rid = RID(-1, -1);
				return 0;
			}
		}
	}

	int pageNum, slotNum;
	curIndexPos.GetPageNum(pageNum);
	curIndexPos.GetSlotNum(slotNum);
	++slotNum;
	if (compOp == NO_OP || compOp == GE_OP || compOp == GT_OP) {
		PF_PageHandle pageHandle;
		fileHandle -> GetThisPage(pageNum, pageHandle);
		char *data;
		pageHandle.GetData(data);
		IX_PageHdr pageHeader;
		memcpy(&pageHeader, data, sizeof(IX_PageHdr));
		if (slotNum < pageHeader.num) {
			curIndexPos = RID(pageNum, slotNum);
			IX_TreeNode treeNode;
			CopyNodeFrom(data + sizeof(IX_PageHdr) + slotNum * nodeSize, treeNode);
			rid = treeNode.rid;
		} else {
			IX_TreeNode treeNode;
			int nextPageNum = pageHeader.next;
			if (nextPageNum != -1) {
				PF_PageHandle nextPageHandle;
				fileHandle -> GetThisPage(nextPageNum, nextPageHandle);
				char *nextData;
				nextPageHandle.GetData(nextData);
				curIndexPos = RID(nextPageNum, 0);
				CopyNodeFrom(data + sizeof(IX_PageHdr), treeNode);
				rid = treeNode.rid;
				rc = fileHandle -> UnpinPage(nextPageNum);
				if (rc < 0) {
					return rc;
				}
			} else {
				rid = RID(-1, -1);
				curIndexPos = RID(-1, -1);
			}
		}
		rc = fileHandle -> UnpinPage(pageNum);
		if (rc < 0) {
			return rc;
		}
	} else if (compOp == LE_OP || compOp == LT_OP) {
		PF_PageHandle pageHandle;
		fileHandle -> GetThisPage(pageNum, pageHandle);
		char *data;
		pageHandle.GetData(data);
		IX_PageHdr pageHeader;
		memcpy(&pageHeader, data, sizeof(IX_PageHdr));
		if (slotNum < pageHeader.num) {
			IX_TreeNode treeNode;
			CopyNodeFrom(data + sizeof(IX_PageHdr) + slotNum * nodeSize, treeNode);
			if ((compOp == LE_OP && CompValue((void*)treeNode.pData, value) <= 0) || (compOp == LT_OP && CompValue((void*)treeNode.pData, value) < 0)) {
				rid = treeNode.rid;
				curIndexPos = RID(pageNum, slotNum);		
			} else {
				rid = RID(-1, -1);
				curIndexPos = RID(-1, -1);
			}
		} else {
			IX_TreeNode treeNode;
			int nextPageNum = pageHeader.next;
			if (nextPageNum != -1) {
				PF_PageHandle nextPageHandle;
				fileHandle -> GetThisPage(nextPageNum, nextPageHandle);
				char *nextData;
				nextPageHandle.GetData(nextData);
				CopyNodeFrom(data + sizeof(IX_PageHdr), treeNode);
				if ((compOp == LE_OP && CompValue((void*)treeNode.pData, value) <= 0) || (compOp == LT_OP && CompValue((void*)treeNode.pData, value) < 0)) {
					rid = treeNode.rid;
					curIndexPos = RID(nextPageNum, 0);		
				} else {
					rid = RID(-1, -1);
					curIndexPos = RID(-1, -1);
				}
				rc = fileHandle -> UnpinPage(nextPageNum);
				if (rc < 0) {
					return rc;
				}
			} else {
				rid = RID(-1, -1);
				curIndexPos = RID(-1, -1);
			}
		}
		rc = fileHandle -> UnpinPage(pageNum);
		if (rc < 0) {
			return rc;
		}
	} else if (compOp == NE_OP) {
		while (pageNum != -1) {
			PF_PageHandle pageHandle;
			fileHandle -> GetThisPage(pageNum, pageHandle);
			char *data;
			pageHandle.GetData(data);
			IX_PageHdr pageHeader;
			memcpy(&pageHeader, data, sizeof(IX_PageHdr));
			for (int i = slotNum; i < pageHeader.num; ++i) {
				IX_TreeNode treeNode;
				CopyNodeFrom(data + sizeof(IX_PageHdr) + i * nodeSize, treeNode);
				if (CompValue((void*)treeNode.pData, value) != 0) {
					rid = treeNode.rid;
					curIndexPos = RID(pageNum, i);
					rc = fileHandle -> UnpinPage(pageNum);
					if (rc < 0) {
						return rc;
					}
					return 0;
				}
			}
			rc = fileHandle -> UnpinPage(pageNum);
			if (rc < 0) {
				return rc;
			}
			pageNum = pageHeader.next;
			slotNum = 0;
		}
		rid = RID(-1, -1);
		curIndexPos = RID(-1, -1);
	}
	return 0;
}





//TODO: (1)���RID��RID�ڣ�-1��-1��ʱGetSlotNum��GetPageNum����ʹ��return rc
//      (2)��д���ƽڵ�