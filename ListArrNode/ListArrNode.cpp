#include "ListArrNode.h"
#include <iostream>

ListArrNode::ListArrNode(int b, ListArrNode *next) {
	mArr = new int[b];
	this->setNext(next);
	mUsedSize = 0;
	std::cout << "A ListArrNode was initialized succesfully :D" << std::endl;
}

ListArrNode::~ListArrNode() {
	delete mArr;
}

ListArrNode* ListArrNode::getNext() {
	return mNext;
}

void ListArrNode::setNext(ListArrNode *next) {
	if (mNext != nullptr)
		delete mNext;
	mNext = next;
}

int ListArrNode::operator[](int i) {
	if (this->size() <= i)
		throw "Index Out of Bounds";
	return mArr[i];
}

int ListArrNode::size() {
	return mUsedSize;
}

void ListArrNode::insertAt(int v, int i) {
	if (this->isFull())
		throw "ListArrNode is full, you cannot insert elements";
	this->moveElementsRight(i);
	mArr[i] = v;
}

void ListArrNode::print() {
	std::cout << "[";
	for (int i=0;i<this->size()-1;++i) {
		std::cout << this->mArr[i] << ", ";
	}
	if (!this->isEmpty()) {
		std::cout << this->mArr[this->size()-1];
	}
	std::cout << "]";
}

bool ListArrNode::find(int v) {
	for (int i=0;i<mUsedSize;++i) {
		if (mArr[i] == v) return true;
	}
	return false;
}

bool ListArrNode::isEmpty() {
	return !this->size();
}

bool ListArrNode::isFull() {
	return this->size() == b;
}

void ListArrNode::moveElementsRight(int i) {
	for (int j=mUsedSize;j>i;--j) {
		mArr[j] = mArr[j-1];
	}
}

int* ListArrNode::getPointerToPos(int i) {
	return mArr+i;
}