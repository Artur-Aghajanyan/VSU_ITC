#include <iostream>
#include <cstring>

template<class T>
class Array{
	
		public:
		
		Array();

		void push(T a);
		void print();
		void pop();
		void erase(int index);
		private:
		T* data;
		int size;

		public:
		~Array(){
		delete[] data;
		}
};

template<class T>
Array<T>::Array(){
	data = nullptr;
	size = 0;
}

template<class T>
void Array<T>::push(T a){
	T* newdata = new T[size+1];
	if(data){
	std :: copy (data,data+size,newdata);
	}
	++size;
	delete[] data;
	data = newdata;
	data[size-1] = a;	
}

template<class T>
void Array<T>::print(){
	
	for(int i = 0;i < size;i++){
		std::cout << data[i] << "\n";
	}

}

template<class T>
void Array<T>::pop(){
	T* newdata = new T[size -1];
	if(data){
			std :: copy (data,data+size-1,newdata);
	}
	--size;
	delete[] data;
	data = newdata;
}


template<class T>
void Array<T>::erase(int index){
	T* newdata = new T[size-1];
	if(data){
	std::copy(data, data+index, newdata);
	std::copy(data+index+1, data+size, newdata+index);
	}
	--size;
	delete[] data;
	data = newdata;
}




