#include <iostream>
#include "vector.h"
using namespace std;

Vector::Vector()
{
    size = 0;
    capacity = 0;
    vec = nullptr;
    cout << "Default constructor \n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    cout << "-------------------------------";
}

Vector::~Vector()
{
    delete [] vec;
    cout << "Vector class destructor\n";
}

Vector::Vector(int a)
{
    size = a;
    capacity = size + 10;
    vec = nullptr;
    cout << "Constructor with one parametr\n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    cout << "-------------------------------\n";
}

Vector::Vector(int s, int value)
{
    size = s;
    capacity = size + 10;
    vec = new int[size];
	for(int i = 0; i < size; ++i)
	{
		vec[i] = value;
	}
	cout << "Constructor with two parametr\n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    for(int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------\n";
}

void Vector::push_back(int element)
{
    if(size == capacity)
    {
        capacity = size + 10;
        int* newVec = new int[capacity];
        if(vec)
        {
        	for(int i = 0; i < size; ++i)
        	{
        	    newVec[i] = vec[i];
            }
        }
        delete[] vec;
        vec = newVec;
        vec[size] = element;
        ++size;
    }else{
        vec[size] = element;
        ++size;
    }
    cout << "Call push_back function \n";
	for(int i = 0; i < size; ++i)
	{
    	 cout << vec[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------\n";
}

void Vector::insert(int index, int value)
{
    if(size == 0 || size <= index) return;
    if(size == index + 1)
    {
        push_back(value);
        return;
    }
    int* vector = new int[size + 1];
    for(int i = 0; i < index; ++i)
    {
        vector[i] = vec[i];
    }
    vector[index] = value;
    for(int i = index; i < size; ++i)
    {
        vector[i + 1] = vec[i];
    }
    delete[] vec;
    vec = vector;
    ++size;
    cout << "Call insert function\n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    for(int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------\n";
}

int Vector::vectorSize()
{
    cout <<"Call size function\n";
    cout <<"Size of vector is  " << size << "\n";
    cout << "-------------------------------\n";
    return size;
}

bool Vector::empty()
{
    if(vec)
    {
        cout << "Vector is not empty \n";
        cout << "-------------------------------\n";
        return 1;
    }else{
        cout << "Vector is empty\n";
        cout << "-------------------------------\n";
        return 0;
    }
}

void Vector::pop_back()
{
    int* vector = new int[size - 1];
    if(size)
    {
        for(int i = 0; i < size - 1; ++i)
        {
            vector[i] = vec[i];
        }
    }
    --size;
    delete[] vec;
    vec = vector;
    cout << "Call pop_back function\n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    for(int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------\n";
}

void Vector::erase(int index)
{
    if(size == 0 || size <= index) return;

    int* vector = new int[size - 1];
    for(int i = 0; i < index; ++i)
    {
        vector[i] = vec[i];
    }
    for(int i = index; i < size; ++i)
    {
        vector[i] = vec[i + 1];
    }
    delete[] vec;
    vec = vector;
    --size;
    cout << "Call erase function\n";
    cout << "size = " << size << "\n";
    cout << "capacity = " << capacity << "\n";
    for(int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------\n";
}

