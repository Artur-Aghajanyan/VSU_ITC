#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>

template <class T>
class Array {
	public:
		Array();
		void push(T a);
		void pop();
		void print();
		void erase(int index);
		~Array();
	private:
		std :: string * data;
		int size;
};

template <class T>
Array <T> :: Array() {
	data = nullptr;
	size = 0;
}

template <class T>
void Array <T> :: push(T a) {
	T* newdata = new T[size + 1];
	if (data) {
		std :: copy(data, data + size, newdata);
	}
	++size;
	delete [] data;
	data = newdata;
	data[size - 1] = a;
}

template <class T>
void Array <T> :: pop() {
	T* newdata = new T[size - 1];
	if (data) {
		std :: copy(data, data + size, newdata);
	}
	--size;
	delete [] data;
	data = newdata;
}

template <class T>
void Array <T> :: print() {
	for (int i = 0; i < size; i++) {
		std :: cout << data[i] << ' ';
	}
}

template <class T>
void Array <T> :: erase(int index) {
	T* newdata = new T [size - 1];
	if (data) {
		std :: copy(data, data + size, newdata);
		std :: copy(data + index + 1, data + (size - index), newdata + index);
	}
	--size;
	delete [] data;
	data = newdata;
}

template <class T>
Array <T> :: ~Array() {
	delete [] data;
}

int main() {
	Array <std :: string> a;
	while(true) {
		std :: string s;
		std :: cin >> s;
		if (s == "end") {
			break;
		}
		a.push(s);
	}
		a.print();
}
