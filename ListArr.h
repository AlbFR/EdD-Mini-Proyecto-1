#ifndef ListArr_h
#define ListArr_h

#include "ListArrADT.h"
#include "ListArrNode.h"
#include "TreeNode.h"

class ListArr: ListArrADT {
	public:
	 	ListArr(int b);
		int size();
		void insertLeft(int v);
		void insertRight(int v);
		void insertAt(int v, int i);
		void print();
		bool find(int v);

	private:
		int b;
		ListArrNode *mHead;
		TreeNode *mTree;

};

#endif