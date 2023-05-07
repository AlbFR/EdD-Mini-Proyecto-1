#include "TreeNode.h"
#include <iostream>

int TreeNode::init(ListArrNode *listNode, int level) {
	if (!level) { // The node is a leaf
		isLeaf = true;
	 	ListArrNode *left = listNode;
		if (left == nullptr) {
			this->setValue(0);
			return 0;
		}
		ListArrNode *right = listNode->getNext();

		this->setLeftChild(left);

		mElementsAmount = left->size();
		if (right == nullptr) {
			return mElementsAmount;
		}

		this->setRightChild(right);

		listNode = right->getNext();
		mElementsAmount += right->size();
		return mElementsAmount;
	}
	else {
		isLeaf = false;

		TreeNode *left = new TreeNode();
		TreeNode *right = new TreeNode();

		if (listNode == nullptr) {
			mElementsAmount = 0;
			return 0;
		}
		left->init(listNode, level-1);
		this->setLeftChild(left);

		mElementsAmount = left->size();
		if (listNode == nullptr) return mElementsAmount;

		mElementsAmount += right->init(listNode, level-1);
		this->setRightChild(right);
		return mElementsAmount;
	}
}

void TreeNode::setValue(int s) {
	if (s < 0)
		throw "Invalid TreeNode size, must be a non-negative integer";
	mElementsAmount = s;
}

int* TreeNode::getPointerToPos(int i) {
	if (isLeaf) {
		int lower_size = mLeftListArrChild->size();
		if (lower_size < i)
			return mLeftListArrChild->getPointerToPos(i);
		else
			return mRightListArrChild->getPointerToPos(i-lower_size);
	}
	int lower_size = mLeftChild->size();
	if (lower_size < i)
		return mLeftChild->getPointerToPos(i);
	else
		return mRightChild->getPointerToPos(i-lower_size);
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

void TreeNode::print() {
	std::cerr << "TreeNode::print() not implemented yet" << std::endl;
}

bool TreeNode::isSpaceNextToPos(int i) {
	int lower_size;
	if (isLeaf) {
		lower_size = mLeftListArrChild->size();
		if (lower_size < i)
			return mLeftListArrChild->isFull();
		else
			return mRightListArrChild->isFull();
	}
	lower_size = mLeftChild->size();
	if (lower_size < i)
		return mLeftChild->isSpaceNextToPos(lower_size-i);
	else
		return mRightChild->isSpaceNextToPos(lower_size-i);
}
