#include <iostream>
#include "ListArr.h"

int main() {
	int b = 4;
	ListArr *la = new ListArr(b);

	la->insertLeft(4);
	la->insertAt(5, 1);
	la->insertLeft(6);

	la->insertLeft(10);
	la->insertAt(100, 2);

	la->insertLeft(3);

	la->print();
	la->printTree();
	std::cout << std::endl;

	la->insertAt(5, 2);
	la->print();
	la->insertAt(6, 2);
	la->print();
	la->insertAt(7, 2);
	la->print();
	la->insertAt(8, 2);
	la->print();
	la->insertAt(5, 7);
	la->print();
	la->insertAt(5, 1);

	la->print();
	la->printTree();
	delete la;
}