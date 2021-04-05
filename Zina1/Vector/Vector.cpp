#include <iostream>
#include <memory.h>
#include "Vector.h"

Vector :: Vector() {
	vector = nullptr;
	size = 0;
}

Vector :: Vector(int s) {
	size = s;
}

Vector :: Vector(int s, int val) {
	vector = new int[s];
	
	for(int i = 1; i <= s; ++i) {
		vector[i] = val;
	}
}

Vector :: Vector(const Vector &v) {
	this -> size = v.size;
	this -> vector = new int[size];
	memcpy(this -> vector, v.vector, size * 4);
}

int Vector :: Size() {
	int s;
	
	if(vector != nullptr) {
		s = sizeof(this -> vector) / sizeof(this -> vector[0]);
		return s;
	} else {
		return 0;
	}
}

int Vector :: capacity() {
	return this -> size + 10;
}

void Vector :: popBack() {
	int *newvector = new int[size - 1];
	
	for(int i = 0; i < size; ++i) {
		memcpy(newvector, vector, size * 4);
	}
	
	--size;
	delete [] vector;
	vector = newvector;
}

void Vector :: pushBack(int val) {
	int *newvector = new int[size + 1];
	
	for(int i = 0; i <= size; ++i) {
		memcpy(newvector, vector, size * 4);
	}
	
	++size;
	delete [] vector;
	vector = newvector;
	vector[size - 1] = val;
}

void Vector :: insert(int index, int val) {
	int *newvector = new int[size + 1];
	
	for(int i = 0; i < index; ++i) {
		newvector[i] = vector[i];
	}
	
	newvector[index] = val;
	
	for(int i = index + 1; i <= size; ++i) {
		newvector[i] = vector[i - 1];
	}
	
	++size;
	delete [] vector;
	vector = newvector;
}

void Vector :: print() {
	for (int i = 0; i < size; ++i) {
		std :: cout << vector[i] << ' ';
	}
}

bool Vector :: empty() {
	if (size == 0) {
		return true;
	} else {
		return false;
	}
}

int& Vector :: operator[](int i) {
    if(i > size) {
        return -1;
    } 
    return arr[i];
}
