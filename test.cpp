#include <iostream>
#include "ListArr.h"

int main() {
	int b = 6;
	ListArr *la = new ListArr(b);
	la->insertLeft(4);
	la->print();
	std::cout << la->size() << std::endl;
	delete la;
}