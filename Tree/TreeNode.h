#ifndef TreeNode_h
#define TreeNode_h

#include "/home/albfr/udec/estructuraDeDatos/EdD-Mini-Proyecto-1/ListArrNode/ListArrNode.h"

class TreeNode {
	public:
		// bool init(ListArrNode *listNode, int level);
		~TreeNode();
		int init(ListArrNode *listNode, int level);
		void setValue(int s);
		TreeNode* getLeftChild();
		TreeNode* getRightChild();
		ListArrNode* getLeftListArrChild();
		ListArrNode* getRightListArrChild();
		void setLeftChild(TreeNode*);
		void setRightChild(TreeNode*);
		void setLeftChild(ListArrNode*);
		void setRightChild(ListArrNode*);
		int size();
		void update();
		void print();
		int* getPointerToPos(int i, bool &newNode);
		bool isSpaceNextToPos(int i);
		ListArrNode* getListArrNodeFromPos(int i, int &m);

	private:
		bool isLeaf;
		int mElementsAmount;
		ListArrNode *mLeftListArrChild;
		ListArrNode *mRightListArrChild;
		TreeNode *mLeftChild;
		TreeNode *mRightChild;

};

#endif
