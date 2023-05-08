#include "TreeNode.h"
#include <iostream>

TreeNode::~TreeNode() {
	if (mRightChild != nullptr) delete mRightChild;
	if (mLeftChild != nullptr) delete mLeftChild;
}

int TreeNode::init(ListArrNode *listNode, int level) {
	if (!level) { // The node is a leaf
		isLeaf = true;
		listNode->print();
	 	ListArrNode *left = listNode;
		if (left == nullptr) {
			mElementsAmount = 0;
			return 0;
		}
		ListArrNode *right = listNode->getNext();
		if (right == nullptr)
			return mElementsAmount;
		std::cout << "ListNode has moved from ";
		listNode->print();
		this->setLeftChild(left);
		std::cout << " to ";


		mElementsAmount = left->size();
		listNode = left->getNext();

		listNode->print();
		std::cout << std::endl;
		if (right == nullptr) {
			return mElementsAmount;
		}

		this->setRightChild(right);

		std::cout << "ListNode has moved from ";
		listNode->print();
		listNode = right->getNext();
		std::cout << " to ";
		listNode = left->getNext();
		std::cout << std::endl;
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
		mElementsAmount = mLeftListArrChild->size();
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
	std::cerr << "m has been turned to " << m << std::endl;
	if (work->isFull()) {
		work->mitosis(m);	
		newNode = true;
	}
	else
		work->moveElementsRight(m);
	return work->getPointerToPos(m);
}

bool TreeNode::isSpaceNextToPos(int i) {
	int m;
	ListArrNode *work = this->getListArrNodeFromPos(i, m);
	if (work->isFull())
		return false;
	work->moveElementsRight(m);
	return true;
	
}

// m is i mapped to the ListArrNode
ListArrNode* TreeNode::getListArrNodeFromPos(int i, int &m) {
	int lower_size;
	if (isLeaf) {
		lower_size = mLeftListArrChild->size();
		if (lower_size < i) {
			m = i;
			return mLeftListArrChild;
		}
		else {
			m = i - lower_size;
			return mRightListArrChild;
		}
	}	
	lower_size = mLeftChild->size();
	if (lower_size < i)
		return mLeftChild->getListArrNodeFromPos(i, m);
	else
		return mRightChild->getListArrNodeFromPos(i-lower_size, m);
}
