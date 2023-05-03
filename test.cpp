#include <iostream>
#include "ListArr.h"

int main() {
	int b = 6;
	ListArr *la = new ListArr(b);
	std::cout << la->size() << std::endl;
}