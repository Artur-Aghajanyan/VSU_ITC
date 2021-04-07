#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H



class Node {
	public:
		int value;
		Node* next;
		Node* previous;
};

class Double_linked_list {
	public:
		Double_linked_list();
		Node* begin; 
		
		void push(int val);
		void print();
		void pop();
};

#endif
