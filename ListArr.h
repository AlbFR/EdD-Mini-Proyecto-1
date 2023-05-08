#ifndef ListArr_h
#define ListArr_h

#include "ListArrADT.h"
#include "ListArrNode/ListArrNode.h"
#include "Tree/TreeNode.h"

class ListArr: ListArrADT {
	public:
	 	ListArr(int b);
		~ListArr();
		int size();
		void insertLeft(int v);
		void insertRight(int v);
		void insertAt(int v, int i);
		bool find(int v) const;
		void print();
		void printTree();

	private:
		int b;
		int mNodesAmount;
		ListArrNode *mHead;
		// ListArrNode *mTail;
		TreeNode *mTree;
		int* getPointerToPos(int i, bool &newNode);
		void initTree();
		void deleteTree();
		void deleteList();
		bool isSpaceNextToPos(int i) const;
		int calculateHeight(int n);

};

#endif