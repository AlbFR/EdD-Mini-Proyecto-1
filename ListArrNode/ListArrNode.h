#ifndef ListArrNode_h
#define ListArrNode_h

class ListArrNode {
	public:
		ListArrNode(int b, ListArrNode *next);
		~ListArrNode();
		ListArrNode* getNext();
		void setNext(ListArrNode *next);
		int operator[](int i);
		int size();
		void insertAt(int v, int i);
		void print();
		bool isEmpty();
		bool isFull();
		bool find(int v);
		int* getPointerToPos(int i);

	private:
		int b;
		int mUsedSize;
		ListArrNode* mNext;
		int *mArr;
		void moveElementsRight(int i);
};

#endif