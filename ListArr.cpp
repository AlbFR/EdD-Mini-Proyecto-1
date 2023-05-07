#include "ListArr.h"
#include <iostream>
#include <cmath>

ListArr::ListArr(int b) {
	this->b = b;
	this->mNodesAmount = 1;
	mHead = new ListArrNode(b, nullptr);
	mTree = new TreeNode();
	mTree->init(mHead, 0);
}

int ListArr::size() {
	return mTree->size();
}

void ListArr::insertLeft(int v) {
	this->insertAt(v, 0);
}

void ListArr::insertRight(int v) {
	this->insertAt(v, this->size()-1);
}

void ListArr::insertAt(int v, int i) {
	if (i == 0)
		this->insertLeft(v);
	if (isSpaceNextToPos(i-1)) {

	}	

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

int* ListArr::getPointerToPos(int i) {
	return mTree->getPointerToPos(i);
}

void ListArr::initTree() {
	int n = mNodesAmount;
	const int levels = (int)ceil(log(n)/log(2));
	mTree->setValue(mTree->init(mHead, levels));
}

bool ListArr::isSpaceNextToPos(int i) const {
	return mTree->isSpaceNextToPos(i);
}