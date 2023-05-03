#ifndef TreeNode_h
#define TreeNode_h

#include "/home/albfr/udec/estructuraDeDatos/EdD-Mini-Proyecto-1/ListArrNode/ListArrNode.h"

class TreeNode {
	public:
	 	bool isLeaf;
		void init(ListArrNode *l, ListArrNode *r);
		void init(TreeNode *l, TreeNode *r);
		TreeNode* getLeftChild();
		TreeNode* getRightChild();
		ListArrNode* getLeftListArrChild();
		ListArrNode* getRightListArrChild();
		int getLeftChildSize();
		int getRightChildSize();
		void setLeftChild(TreeNode*);
		void setRightChild(TreeNode*);
		void setLeftChild(ListArrNode*);
		void setRightChild(ListArrNode*);
		int size();
		void update();
		int initNode(TreeNode *tn);

	private:
		int mElementsAmount;
		ListArrNode *mLeftListArrChild;
		ListArrNode *mRightListArrChild;
		TreeNode *mLeftChild;
		TreeNode *mRightChild;

};

#endif
