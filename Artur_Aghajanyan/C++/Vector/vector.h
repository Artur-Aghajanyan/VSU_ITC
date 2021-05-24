#include <iostream>

using namespace std;
template <class T>
class Vector {
	private:
		int x;
		T* array;	
	public:
		Vector();
		Vector(int count);
		Vector(int count, T value);
		Vector(const Vector& vector);
		void insert(int index, T value);
		int size();
		bool empty();
		void push_back(T value);
		void pop_back();
		T &operator[](int index);
		~Vector();
};

template <class T>
Vector<T>::Vector() {
	this->x = 0;
	this->array = nullptr;
}

template <class T>
Vector<T>::Vector(int countOfElements) {
	this->x = countOfElements;
	this->array = new T[countOfElements];
}

template <class T>
Vector<T>::Vector(int countOfElements, T value) {
	this->x = countOfElements;
	this->array = new T[countOfElements];
	for(int i = 0; i < countOfElements; ++i)
		this->array[i] = value;
}

template <class T>
Vector<T>::Vector(const Vector& vector) {
	this->x = vector.x;
	copy(this->array, this->array + x, vector.array);
}

template <class T>
void Vector<T>::insert(int index, T value) {
	T* newArray = new T[this->x+1];
	if(this->array) {
		copy(this->array, array + index, newArray);
		copy(this->array + index + 1, array + x, newArray + index);
	}
	newArray[index] = value;
	++this->x;
	delete[] array;
	this->array = newArray;
}

template <class T>
int Vector<T>::size() {
	return this->x;
}

template <class T>
bool Vector<T>::empty() {
	if(this->array) {
		return true;
	}
	return false;
}

template <class T>
void Vector<T>::pop_back() {
	T* newArray = new T[this->x - 1];
	if(this->array)
		copy(this->array, this->array+this->x-1, newArray);

	--this->x;
	delete[] this->array;
	this->array = newArray;
}

template <class T>
void Vector<T>::push_back(T value) {
	T* newArray = new T[this->x + 1];

	if(this->array) 
		copy(this->array, this->array + this->x + 1, newArray);

	++this->x;
	newArray[x] = value;
	delete[] this->array;
	this->array = newArray;
}

template <class T>
T &Vector<T>::operator[](int index){
	if(index > x)
		return this->array[this->x-1];
	if(index <= 0)
		return this->array[0];
	return this->array[index];
}

template <class T>
Vector<T>::~Vector() {
	delete[] this->array;
}
