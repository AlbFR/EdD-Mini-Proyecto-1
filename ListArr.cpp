#include "ListArr.h"
#include <iostream>

ListArr::ListArr(int b) {
	this->b = b;
	this->mNodesAmount = 1;
	mHead = new ListArrNode(b, nullptr);
	mTree = nullptr;
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

bool ListArr::find(int v) {
	ListArrNode *current = mHead;
	while (current != nullptr) {
		if (current->find(v)) return true;
		current = current->getNext();
	}
	return false;
}

int* getPointerToRank(TreeNode *treeNode, int i) {

}

void initTree(TreeNode *tn) {

}