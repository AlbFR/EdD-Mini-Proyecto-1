#ifndef ListArr_h
#define ListArr_h

#include "ListArrADT.h"

class ListArr: ListArrADT {
	public:
	 	ListArr(int b);
		int size();
		void insertLeft(int v);
		void insertRight(int v);
		void insertAT(int v, int i);
		void print();
		bool find(int v);


};

#endif