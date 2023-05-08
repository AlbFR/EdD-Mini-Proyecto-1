#include <iostream>
#include "ListArr.h"

int main() {
	int b = 6;
	ListArr *la = new ListArr(b);
	// la->printTree();
	// la->print();
	// std::cout << std::endl;

	la->insertLeft(4);
	la->printTree();
	la->print();
	std::cout << std::endl;

	la->insertLeft(6);
	la->printTree();
	la->print();
	std::cout << std::endl;

	la->insertLeft(10);
	la->printTree();
	la->print();
	std::cout << std::endl;

	la->insertLeft(3);
	la->printTree();
	la->print();
	std::cout << std::endl;
	// la->print();
	// la->insertAt(5, 2);
	// la->print();
	delete la;
}