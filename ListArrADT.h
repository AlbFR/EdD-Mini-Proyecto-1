#ifndef ListArrADT_h
#define ListArrADT_h

class ListArrADT {
	// Returns amount of elements stored in ListArr
	virtual int size() = 0;

	// Inserts a new value v at left of ListArr i.e. inserts v at index 0
	virtual void insertLeft(int v) = 0;

	// Inserts a new value v at right of ListArr i.e. inserts v at index size()-1
	virtual void insertRight(int v) = 0;

	// Inserts a new value v at index i of ListArr
	virtual void insertAt(int v, int i) = 0;

	// Prints on screen all values stored in ListArr
	virtual void print() = 0;

	// Returns true if value v exists in ListArr, otherwise returns false
	virtual bool find(int v) = 0;
};

#endif
