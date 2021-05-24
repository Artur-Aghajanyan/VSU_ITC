#ifndef STACK_H
#define STACK_H

class Stack {
	int  count;
	char* array;
	public:
	Stack();
	void push(char value);
	void pop();
	bool check(char bracket);
	bool check_array();
};

#endif

