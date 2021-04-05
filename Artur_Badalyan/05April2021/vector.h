#include <iostream>
using namespace std;


class Vector {
    public:
    Vector();
    Vector(int size);
    Vector(int size,int value);
    Vector(const Vector &other);
    ~Vector();

    void push_back(int value);
    int pop_back();
    void insert(int index,int value);
    int vec_size();
    bool empty();

    int &operator[](int i);
    

    private:
    int *array;
    int size;
};