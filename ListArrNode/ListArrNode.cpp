#include "ListArrNode.h"

ListArrNode::ListArrNode(int b, ListArrNode *next) {
	mArr = new int[b];
	this->setNext(next);
	this->mUsedSize = 0;
}

ListArrNode::~ListArrNode() {
	delete mArr;
}

ListArrNode* ListArrNode::getNext() {
	return this->mNext;
}

void ListArrNode::setNext(ListArrNode *next) {
	if (this->mNext != nullptr)
		delete this->mNext;
	this->mNext = next;
}

int ListArrNode::operator[](int i) {
	if (this->size() <= i)
		throw "Index Out of Bounds";
	return mArr[i];
}

int ListArrNode::size() {
	return this->mUsedSize;
}

void ListArrNode::insertAt(int v, int i) {
	if (this->isFull())
		throw "ListArrNode is full, you cannot insert elements";
	this->moveElementsRight(i);
	this->mArr[i] = v;
}

bool ListArrNode::isFull() {
	return this->size() == b;
}

void ListArrNode::moveElementsRight(int i) {
	for (int j=this->size();j>i;--j) {
		this->mArr[j] = this->mArr[j-1];
	}
}