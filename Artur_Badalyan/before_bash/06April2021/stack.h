#include <iostream>
using namespace std;

template <class T>
class Stack{
	public:
	Stack();
	Stack(int size);
	~Stack();

	bool empty();
	int size();
	void push(T value);
	void pop();
	T top();

	private:
	int count;
	int index;
	T* array;	
		
};

template <class T>
Stack<T>::Stack() { 
	this->count = 5;
	this->index = -1;
	array = new T[count];
}

template <class T>
Stack<T>::Stack(int count) {
	this->count = count;
	this->index = -1;
	array = new T[count];	
}

template <class T>
Stack<T>::~Stack() {
	delete[] array;
}

template <class T>
void Stack<T>::push(T value){
	if(index == count-1){
		cerr << "Stack is a full"<<endl;
		return;
	}
	++index;
	array[index] = value;
}

template <class T>
void Stack<T>::pop(){
	if (index == -1){
		return;
	}
	--index;
}

template <class T>
int Stack<T>::size(){
	return this->count;
}

template <class T>
bool Stack<T>::empty(){
	if (index == -1){
		return true;
	}
	return false;
}

template <class T>
T Stack<T>::top(){
	if (index == -1){
		return (T)NULL;
	}	
	return this->array[index];
}
