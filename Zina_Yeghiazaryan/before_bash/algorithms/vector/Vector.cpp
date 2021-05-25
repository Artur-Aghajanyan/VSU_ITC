#include <iostream>
#include <memory.h>
#include "vector.h"

Vector :: Vector() {
    vector = nullptr;
    size = 0;
}

Vector :: Vector(int s) {
    size = s;
}

Vector :: Vector(int s, int val) {
    vector = new int[s];
    size = s;
    for(int i = 0; i < s; ++i) {
        vector[i] = val;
    }
}

Vector :: Vector(const Vector &v) {
    this -> size = v.size;
    this -> vector = new int[size];
    memcpy(this -> vector, v.vector, size * 4);
}

int Vector :: Size() {
    return size;
}

int Vector :: capacity() {
    return this -> size + 10;
}

void Vector :: popBack() {
    int *newvector = new int[size - 1];
    memcpy(newvector, vector, (size - 1) * 4);
    --size;
    delete [] vector;
    vector = newvector;
}

void Vector :: pushBack(const int& val) {
    int *newvector = new int[size + 1];
    memcpy(newvector, vector, size * 4);
    newvector[size - 2] = val;
    delete [] vector;
    vector = newvector;
    ++size;
}

void Vector :: insert(int index, int val) {
    int *newvector = new int[size + 1];

    for(int i = 0; i < index; ++i) {
        newvector[i] = vector[i];
    }

    newvector[index] = val;

    for(int i = index; i < size; ++i) {
        newvector[i + 1] = vector[i];
    }

    ++size;
    delete [] vector;
    vector = newvector;
}

void Vector :: print() {
    for (int i = 0; i < size; ++i) {
        std :: cout << vector[i] << ' ';
    }
    std :: cout << std :: endl;
}

bool Vector :: empty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

int& Vector :: operator[](int i) {
    if (i > size - 1) {
        std :: cout << "out of range";
        return vector[0];
    }
    return vector[i];
}
