#include "ListArr.h"

ListArr::ListArr(int b) {
	this->b = b;
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

}

bool ListArr::find(int v) {

}