#ifndef ListArr_h
#define ListArr_h

#include "ListArrADT.h"
#include "ListArrNode/ListArrNode.h"
#include "Tree/TreeNode.h"

class ListArr: ListArrADT {
	public:
	 	ListArr(int b);
		int size();
		void insertLeft(int v);
		void insertRight(int v);
		void insertAt(int v, int i);
		void print();
		bool find(int v) const;

	private:
		int b;
		int mNodesAmount;
		ListArrNode *mHead;
		TreeNode *mTree;
		int* getPointerToPos(int i);
		void initTree();
		bool isSpaceNextToPos(int i) const;

};

#endif