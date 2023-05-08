#include <iostream>
#include "ListArr.h"

int main() {
	int b = 6;
	ListArr *la = new ListArr(b);

	// la->printTree();
	// la->print();
	// std::cout << std::endl;

	// ListArrNode *lan = new ListArrNode(b, nullptr);
	// lan->insertRight(20);
	// lan->insertRight(10);
	// lan->insertRight(14);
	// ListArrNode *las = new ListArrNode(b, lan);
	// las->insertRight(3);
	// las->insertRight(2);
	// TreeNode *head = new TreeNode();
	// head->init(las, 0);

	// ListArrNode *lax = new ListArrNode(b, las);
	// lax->insertRight(23);
	// head->init(lax, 1);
	// head->print();

	la->insertLeft(4);
	la->print();
	la->printTree();
	std::cout << std::endl;

	la->insertLeft(6);
	la->print();
	la->printTree();
	std::cout << std::endl;

	la->insertLeft(10);
	la->print();
	la->printTree();
	std::cout << std::endl;

	la->insertLeft(3);
	la->print();
	la->printTree();
	std::cout << std::endl;
	la->print();
	la->insertAt(5, 2);
	la->print();
	delete la;
}