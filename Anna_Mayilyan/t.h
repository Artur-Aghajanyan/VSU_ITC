#include <iostream>
template <class T> 
class Array{
public:
        Array();
        void push(T num);
        void get();
      void pop();
    ~Array();
private:
        T* data;
        int size;
};
template <class T>
Array<T>::Array()
{
        data = nullptr;
        size = 0;
}
template <class T>
void Array<T>::push(T num)
{
T* newdata1 = new T[size+1];
        if(size)
	{
	      for(int i=0; i< size; i++){
		      newdata1[i]=data[i];}
        }
        ++size;
        delete[] data;
        data = newdata1;
        data[size-1] = num;
}
template <class T>
void Array<T>::get()
{
        for(int i=0;i<size; i++)
	{
        std::cout<<data[i]<<"  ";
}
}


template <class T>
void Array<T>::pop(){
       T* newdata2 = new T[size-1];
        if(size)
	{
	       for(int i=0; i< size-1; i++){
		       newdata2[i]=data[i];}
        }
        --size;
        delete[] data;
        data = newdata2;
}

template <class T>
Array<T>::~Array(){
        delete[] data;
}
