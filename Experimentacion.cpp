#include <iostream>
#include <chrono>
using namespace std;

class TestArray {
public:	
	int size;
	int sizeUsed;
	int* array;

	TestArray(int n) {
		this->size = n;
		this->sizeUsed = 0;
		this->array = new int[n];
	}

	~TestArray() {
		delete[] array;
	}

	void insert_left(int v) {
		if (sizeUsed == size) {
			cout << "Arreglo lleno!";
			return;
		}
		int* trash;
		int* aux = new int[size];
		aux[0] = v;
		for (int i = 0; i < sizeUsed; i++) {
			aux[i + 1] = array[i];
		}
		trash = array;
		array = aux;
		this->sizeUsed++;
		delete[] trash;
	}

	void insert_right(int v) {
		if (sizeUsed == size) {
			cout << "Arreglo lleno!";
			return;
		}
		this->array[sizeUsed] = v;
		this->sizeUsed++;
	}

	bool find(int v) {
		for (int i = 0; i < sizeUsed; i++) {
			if (array[i] == v) { return true; }
		}
		return false;
	}

	void print() {
		for (int i = 0; i < sizeUsed; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

class Node {
public:
	int data;
	Node* next;

	Node(int n) {
		data = n;
	}
};

class TestList {
public:
	Node* head;
	Node* rear;
	int size;

	TestList() {
		this->head = NULL;
		this->rear = NULL;
		size = 0;
	}

	void insert_left(int v) {
		Node* insertLeft = new Node(v);
		if (size == 0) {
			head = insertLeft;
			rear = insertLeft;
			insertLeft->next = NULL;
		}
		else {
			insertLeft->next = head;
			head = insertLeft;
		}
		this->size++;
	}

	void insert_right(int v) {
		Node* insertRight = new Node(v);
		if (size == 0) {
			head = insertRight;
			rear = insertRight;
			insertRight->next = NULL;
		}
		else {
			rear->next = insertRight;
			rear = insertRight;
			insertRight->next = NULL;
		}
		this->size++;
	}

	bool find(int v) {
		Node* trash = new Node(0);
		trash = head;
		for (int i = 0; i < size; i++) {
			if (trash->data == v) {
				return true;
			}
			else {
				trash = trash->next;
			}
		}
		delete trash;
		return false;
	}

	void print() {
		Node* trash = new Node(0);
		trash = head;
		for (int i = 0; i < size; i++) {
			cout << trash->data << " ";
			trash = trash->next;
		}
		cout << endl;
		delete trash;
	}
};

int main() {
	TestArray arreglo = TestArray(4);
	TestList lista = TestList();

	arreglo.insert_left(2);
	arreglo.insert_left(5);
	arreglo.insert_right(4);
	arreglo.insert_right(6);

	arreglo.print();
	if (arreglo.find(4)) {
		cout << "El 4 es parte del arreglo." << endl;
	}
	if (!arreglo.find(10)) {
		cout << "El 10 no es parte del arreglo." << endl;
	}

	cout << endl;

	lista.insert_left(2);
	lista.insert_left(5);
	lista.insert_right(4);
	lista.insert_right(6);

	lista.print();
	if (lista.find(6)) {
		cout << "El 6 es parte del arreglo." << endl;
	}
	if (!lista.find(10)) {
		cout << "El 10 no es parte del arreglo." << endl;
	}

	// Area de experimentacion.
	// Borrar /**/ si es que se planea usar.
	
	/*
	int reps = 5000; // Muestra variable
	srand(time(NULL));
	double duration = 0;
	for (int i = 0; i < 20; i++) {
		TestList lista = TestList();
		for (int j = 0; j < reps; j++) {
			lista.insert_right(1);
		}
		auto start = chrono::high_resolution_clock::now();
		//Inicio del cronómetro
		lista.find(0);
		//Final del cronómetro
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		duration += diff.count();
	}
	duration /= 20;

	cout << "El proceso demoro " << duration << " segundos en promedio." << endl;
	*/
	return 0;
}