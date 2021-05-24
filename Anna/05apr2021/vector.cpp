#include <iostream>
#include "vector.h"

Array::Array(){
	data = nullptr;
	size = 0;

}
Array::Array(int n){
	size = n;
	data = new int[n];
}

Array::Array(const Array &v)
{
	size = v.size;
	data = new int[size];
	for(int i = 0; i < size; i++)
	data[i] = v.data[i];
}


void Array::push (int  a){
	int *newdata = new int[size+1];
if(size){
	for( int i = 0; i< size; i++)
		newdata[i] = data[i];	
}
size++;
delete [] data;
data = newdata;
data[size-1] = a;
}


void Array::insert(int index, int value)
{
int *newdata2 = new int[size+1];
for(int i = 0;  i < size; i++)
	newdata2[i] = data[i];

newdata2[index] = value;
for(int i = index; i <size; i++)
newdata2[i+1] = data[i];

size++;
delete [] data;
data = newdata2;

}

int Array::Size(){
return size;
}

bool Array::empty() {
	if(data == NULL)
		return true;
	else
		return false;
}

int& Array::operator[] (int index){
if(index >= size)
exit(0);
else
return data[index];
}

void Array::pop_back(){
int *newdata3 = new int[size-1];
if(size){
for(int i = 0; i < size-1; i++)
	newdata3[i] = data[i];}
	--size;
	delete [] data;
	data = newdata3;
}

void Array::get(){
for(int i = 0; i < size; ++i)
std::cout<<data[i];
}

Array::~Array(){
delete [] data;
}
