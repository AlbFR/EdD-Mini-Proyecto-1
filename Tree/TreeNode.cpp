#include "TreeNode.h"
#include <iostream>

TreeNode::~TreeNode() {
	if (!isLeaf) {
		if (mRightChild != nullptr) delete mRightChild;
		if (mLeftChild != nullptr) delete mLeftChild;
	}
}

int TreeNode::init(ListArrNode *&listNode, int level) {
	if (!level) { // The node is a leaf
		isLeaf = true;
		if (listNode == nullptr) {
			mElementsAmount = 0;
			return 0;
		}
		this->setLeftChild(listNode);

		mElementsAmount = listNode->size();
		listNode = listNode->getNext();

		if (listNode == nullptr) {
			return mElementsAmount;
		}

		this->setRightChild(listNode);

		mElementsAmount += listNode->size();
		listNode = listNode->getNext();
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
		if (listNode == nullptr) 
			return mElementsAmount;

		right->init(listNode, level-1);
		mElementsAmount += right->size();
		this->setRightChild(right);
		return mElementsAmount;
	}
}

void TreeNode::setValue(int s) {
	if (s < 0)
		throw "Invalid TreeNode size, must be a non-negative integer";
	mElementsAmount = s;
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
	if (isLeaf) {
		if (mLeftListArrChild == nullptr) {
			mElementsAmount = 0;
			return;
		}
		mElementsAmount = mLeftListArrChild->size();
		if (mRightListArrChild == nullptr)
			return;
		mElementsAmount += mRightListArrChild->size();
	}
	else {
		if (mLeftChild == nullptr) {
			mElementsAmount = 0;
			return;
		}
		mLeftChild->update();
		mElementsAmount = mLeftChild->size();
		if (mRightChild == nullptr)
			return;
		mRightChild->update();
		mElementsAmount += mRightChild->size();
	}
}

void TreeNode::print() {
	if (isLeaf) {
		std::cout << this->size() << " (";
		if (mLeftListArrChild != nullptr)
			mLeftListArrChild->print();
		std::cout << ",";
		if (mRightListArrChild != nullptr)
			mRightListArrChild->print();
		std::cout << ") ";
	}
	else {
		std::cout << mElementsAmount << " -> (";
		if (mLeftChild != nullptr)
			mLeftChild->print();
		std::cout << ",";
		if (mRightChild != nullptr)
			mRightChild->print();
		std::cout << ")";
	}
}

int* TreeNode::getPointerToPos(int i, bool &newNode) {
	int m;
	ListArrNode *work = this->getListArrNodeFromPos(i, m);
	m++;
	if (work->isFull()) {
		work->mitosis(m);	
		newNode = true;
	}
	else {
		work->moveElementsRight(m);
	}
	return work->getPointerToPos(m);
}

// m is i mapped to the ListArrNode
ListArrNode* TreeNode::getListArrNodeFromPos(int i, int &m) {
	int lower_size;
	if (isLeaf) {
		lower_size = mLeftListArrChild->size();
		if (lower_size > i) {
			m = i;
			return mLeftListArrChild;
		}
		else {
			m = i - lower_size;
			return mRightListArrChild;
		}
	}	
	lower_size = mLeftChild->size();
	if (lower_size > i)
		return mLeftChild->getListArrNodeFromPos(i, m);
	else
		return mRightChild->getListArrNodeFromPos(i-lower_size, m);
}
