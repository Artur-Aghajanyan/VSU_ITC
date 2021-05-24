#include <iostream>
#include <cstring>
#include <algorithm>
namespace ITC{
	template <class T>
	class Array{
		public:
		void push(T a);
		void print();
		void pop();
		void erasc(int index);	
		Array();
		~Array();
		private:
		T* data;
		int size;
	};
}

template <class T>
ITC::Array<T>::Array(){
	this->data = nullptr;
	this->size = 0;
}

template <class T>
void ITC::Array<T>::push(T a){
	
	T* newdata = new T[size + 1];
	if(data) {
		std::copy(data, data+size, newdata);
	}
	++size;
	delete []data;	
	data = newdata;
	data[size - 1] = a;
}

template <class T>
void ITC::Array<T>::print(){
	for(int i = 0; i < this->size; i++){
		std::cout << this->data[i] << "\n";
	}
}

template <class T>
void ITC::Array<T>::pop(){
	T* newdata = new T[this->size-1];
	if(this->data){
		std :: copy (this->data, this->data+size-1, newdata);
	}
	--this->size;
	delete[] this->data;
	this->data = newdata;
}

template <class T>
void ITC::Array<T>::erasc(int index){
	T* newdata = new T[this->size - 1];
	if(this->data){
		std :: copy (data, data + index, newdata);
        std :: copy (data + index + 1, data + size , newdata + index);
	}
	--this->size;
	delete[] this->data;
	this->data = newdata;
}

template <class T>
ITC::Array<T>::~Array(){
	delete[] this->data;
	std::cout<< "Deleted\n";
}
