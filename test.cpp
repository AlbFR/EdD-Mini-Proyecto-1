#include <iostream>
#include "ListArr.h"
#include <chrono>

int main() {
	int b = 4;
	ListArr *la = new ListArr(b);

	la->insertLeft(4);
	la->print();
	la->insertAt(5, 1);
	la->print();
	la->insertLeft(6);

	la->print();
	la->insertRight(1);
	la->print();
	la->insertRight(2);
	la->print();
	la->insertRight(3);
	la->print();

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
	/*
	int b = 1;
	int reps = 50000; // Muestra variable
    srand(time(NULL));
    double duration = 0;
    for (int i = 0; i < 20; i++) {
        ListArr *la = new ListArr(b);
        for (int j = 0; j < reps; j++) {
            la->insertRight(1);
        }
        auto start = chrono::high_resolution_clock::now();
        //Inicio del cronómetro
        la->find(0);
        //Final del cronómetro
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        duration += diff.count();
        delete la;
    }
    duration /= 20;

    cout << "El proceso demoro " << duration << " segundos en promedio." << endl;
	*/
	delete la;
}