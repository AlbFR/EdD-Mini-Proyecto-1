#include "ListArrNode.h"
#include <iostream>

ListArrNode::ListArrNode(int size, ListArrNode *next) {
	b = size;
	mArr = new int[b];
	this->setNext(next);
	mUsedSize = 0;
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
	mUsedSize++;
}

void ListArrNode::print() {
	std::cout << "[";
	for (int i=0;i<mUsedSize-1;++i) {
		std::cout << mArr[i] << ", ";
	}
	if (!this->isEmpty()) {
		std::cout << mArr[mUsedSize-1];
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
	return !mUsedSize;
}

bool ListArrNode::isFull() {
	return (mUsedSize == b);
}

void ListArrNode::moveElementsRight(int i) {
	if (this->isFull())
		throw "Cannot move elements, the ListArrNode is full";
	for (int j=mUsedSize;j>i;--j) {
		mArr[j] = mArr[j-1];
	}
}

int* ListArrNode::getPointerToPos(int i) {
	return mArr+i;
}

void ListArrNode::insertRight(int v) {
	if (this->isFull())
		throw "Cannot insert at right, The ListArrNode is full";
	mArr[mUsedSize] = v;	
	mUsedSize++;
}

void ListArrNode::mitosis(int i) {
	ListArrNode *neu = new ListArrNode(this->size(), this->getNext());
	for (int j=i;j<this->size();++j) {
		neu->insertRight(*(mArr+j));
	}
	mUsedSize = i+1;
	this->setNext(neu);
}