#include <iostream>

template<class T>
class array
{
public:
    array();
    void push(T a);
    void print();
    void pop();
    void erase(int index);
private:
    T* data;
    int size;
};

template<class T>
array<T>::array()
{
    data = nullptr;
    size = 0;
}

template<class T>
void array<T>::push(T a)
{
    T* newdata = new T[size + 1];
    if(data)
    {
	for(int i = 0; i < size; ++i)
	    newdata[i] = data[i];
    }
    ++size;
    delete[] data;
    data = newdata;
    data[size - 1] = a;
}

template<class T>
void array<T>::print()
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << data[i] << "  ";
    }
}

template<class T>
void array<T>::pop()
{
    T* newdata = new T[size -1];
    if(data)
    {
        for(int i = 0; i < size - 1; i++)
	    {
	        newdata[i] = data[i];
            }
     }
     --size;
     delete[] data;
     data = newdata;
}

template <class T>
void array<T>::erase(int index)
{
    T* newdata = new T[size - 1];
    if(data)
	{
	    for(int i = 0; i < index; ++i)
		{
	            newdata[i] = data[i];
		}
	    for(int i = index; i < size - 1; i++)
		{
	            newdata[i] = data[i + 1];
		}
	    --size;
	    delete[] data;
	    data = newdata;
	}
}







