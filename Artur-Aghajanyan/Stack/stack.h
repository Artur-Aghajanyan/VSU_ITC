#include <iostream>

template <class T>
class Stack{
	private:
		T* array;
		int head;
		int capacity = 5;
	public:
		Stack(int size);
		~Stack();
		T pop();
		T top();
		void push(T value);
		int size();
		bool empty();	
};

template <class T>
Stack<T>::Stack(int s) {
	this->array = new T[capacity];
	this->capacity = s;
	this->head = -1;
}

template <class T>
Stack<T>::~Stack() {
	delete[] this->array;
}

template <class T>
void Stack<T>::push(T value) {
 
	if(this->head == this->capacity-1) {
		std::cout << "Stack is Full !!!\n";
		return;
	}	
	this->head++;
	this->array[head] = value;
}

template <class T>
T Stack<T>::pop() {
	if(this->head == -1) {
		std::cout << "Stack is empty !!!\n";
		return (T)NULL;	
	}
	T res = this->array[head];
	this->head--;
	return res;
}

template <class T>
int Stack<T>::size() {
	return this->head;
}

template <class T>
T Stack<T>::top() {
	return this->array[head];
}

template <class T>
bool Stack<T>::empty() {
	if(head == -1 || capacity == 0)
		return true;
	return false;
} 
