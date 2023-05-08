#include "ListArr.h"
#include <iostream>
#include <cmath>

ListArr::ListArr(int b) {
	this->b = b;
	this->mNodesAmount = 1;
	mHead = new ListArrNode(b, nullptr);
	mTree = new TreeNode();
	mTail = mHead;
	initTree();
}

ListArr::~ListArr() {
	deleteTree();
	deleteList();
}

int ListArr::size() {
	return mTree->size();
}

void ListArr::insertLeft(int v) {
	if (mNodesAmount == 1 && mHead->size() == 0) {
		mHead->insertRight(v);
		mTree->update();
		return;
	}
	ListArrNode *neu = new ListArrNode(b, mHead);
	neu->insertRight(v);
	mHead = neu;
	mNodesAmount++;
	deleteTree();
	mTree = new TreeNode();
	initTree();
}

void ListArr::insertRight(int v) {
	// this->insertAt(v, this->size()-1);
	ListArrNode *neu = new ListArrNode(b, nullptr);
	mTail->setNext(neu);
	neu->insertRight(v);
	mTail = neu;
}

void ListArr::insertAt(int v, int i) {
	if (i < 0 || this->size() < i) {
		throw "Index out of bounds, cannot insert there";
	}
	if (i == 0)
		this->insertLeft(v);

	bool newNode = false;
	*(this->getPointerToPos(i-1, newNode)) = v;
	if (newNode) {
		mNodesAmount++;
		deleteTree();
		mTree = new TreeNode();
		initTree();
	}
	else
		mTree->update();
	if (mTail->getNext() != nullptr)
		mTail = mTail->getNext();
}

void ListArr::print() {
	ListArrNode *current = mHead;
	while (current != nullptr) {
		current->print();
		std::cout << " --> ";
		current = current->getNext();
	}
	std::cout << std::endl;
}

bool ListArr::find(int v) const {
	ListArrNode *current = mHead;
	while (current != nullptr) {
		if (current->find(v)) return true;
		current = current->getNext();
	}
	return false;
}

int* ListArr::getPointerToPos(int i, bool &newNode) {
	return mTree->getPointerToPos(i, newNode);
}

int ListArr::calculateHeight(int n) {
	if (n == 0 || n == 1) return 0;
	return (int)ceil(log(n)/log(2)) - 1;
}

void ListArr::initTree() {
	const int levels = calculateHeight(mNodesAmount);
	ListArrNode *run = mHead;
	mTree = new TreeNode();
	mTree->init(run, levels);
}

bool ListArr::isSpaceNextToPos(int i) const {
	return mTree->isSpaceNextToPos(i);
}

void ListArr::printTree() {
	mTree->print();
	std::cout << std::endl;
}

void ListArr::deleteTree() {
	delete mTree;
}

void ListArr::deleteList() {
	ListArrNode *cr;
	while (mHead != nullptr) {
		cr = mHead;
		mHead = mHead->getNext();
		delete cr;
	}
}