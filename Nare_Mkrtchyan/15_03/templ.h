#include <iostream>
#include <memory.h>

template <class T>
class array{
    public:
        array();
       void push(T a);
       void get();
       bool getType();
       void pop();
       void erase(int index);
       ~array();
    private:
       int size;
       T* data;
     
};

template <class T>
array<T>::array(){
    size = 0;
    data = nullptr;
}

template <class T>
 void array<T>::push(T a){
    T* newdata = new T[size+1];
    if(size){
       // memcpy(newdata,data,size*4);
       for(int i=0; i < size; i++){
            newdata[i]=data[i];
            } 
    }
    ++size;
    delete[] data;
    data = newdata;
    data[size-1] = a;
}


template <class T>
 void array<T>::get(){
        for(int i=0;i<size; i++){
            std::cout<<data[i]<<"  ";
        }
 std::cout<<std::endl;
}

template <class T>
 void array<T>::pop(){
        T* newdata = new T[size-1];
        if(size){
             //   memcpy(newdata,data,(size-1)*4);
                for(int i=0; i < size-1; i++){
                    newdata[i]=data[i];
                }

        }
        --size;
        delete[] data;
        data = newdata;
      //  data[size-1] = a;
}

template <class T>
void array<T>::erase(int index){
       // T* newdata2 = new T[size-index];
        T* newdata1 = new T[size-1];
        if(size){
            for(int i=0; i < index; i++){
                newdata1[i]=data[i]; 
            }
            for(int i=index; i<size-1;i++){
                newdata1[i]=data[i+1];
           }
        }
        --size;
        delete[] data;
        data = newdata1;

}
template <class T>
 array<T>::~array(){
     std::cout<<"destruct"<<std::endl;
    delete[] data;
 }

