#ifndef LIST_H
#define LIST_H
#include <iostream>

struct Node{
	Node* previous;
	Node* next;
	int value;
};
class List{
	private:
		Node* begin;
	public:
		List();
		void push(int value);
		void pop();
		void print();
};
#endif
