#include "TreeNode.h"

void TreeNode::init(ListArrNode *l, ListArrNode *r) {
	mLeftListArrChild = l;
	mRightListArrChild = r;
}

void TreeNode::init(TreeNode *l, TreeNode *r) {
	mLeftChild = l;
	mRightChild = r;
}

TreeNode* TreeNode::getLeftChild() {
	return mLeftChild;
}

TreeNode* TreeNode::getRightChild() {
	return mRightChild;
}

ListArrNode* TreeNode::getLeftListArrChild() {
	return mLeftListArrChild;
}

ListArrNode* TreeNode::getRightListArrChild() {
	return mRightListArrChild;
}

int TreeNode::getLeftChildSize() {
	if (this->isLeaf)
		return mLeftListArrChild->size();
	if (mLeftChild == nullptr)
		return 0;
	return mLeftChild->size();
}

int TreeNode::getRightChildSize() {
	if (this->isLeaf)
		return mRightListArrChild->size();
	if (mRightChild == nullptr)
		return 0;
	return mRightChild->size();
}

void TreeNode::setLeftChild(TreeNode *lan) {
	mLeftChild = lan;
}

void TreeNode::setRightChild(TreeNode *lan) {
	mRightChild = lan;
}

void TreeNode::setLeftChild(ListArrNode *lan) {
	mLeftListArrChild = lan;
}

void TreeNode::setRightChild(ListArrNode *lan) {
	mRightListArrChild = lan;
}

int TreeNode::size() {
	return mElementsAmount;
}

void TreeNode::update() {
	mElementsAmount = mLeftChild->size();
	if (mRightChild != nullptr)
		mElementsAmount += mRightChild->size();
}

int initNode(TreeNode *tn) {

}