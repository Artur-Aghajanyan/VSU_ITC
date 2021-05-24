#include <iostream>
#ifndef STEACK_H
#define STEACK_H 



class  Stack {
    private:
	int count;
	int* array;
	public:
	Stack ();
	void push(int value);
	void pop();
	void print();
	int size();
};

 

#endif
