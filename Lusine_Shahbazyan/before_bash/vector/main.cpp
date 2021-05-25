#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    cout << "Vector Class \n";
    Vector myVector1;
    cout << endl;
    Vector myVector2(5);
    Vector myVector3(4, 7);
    myVector3.pop_back();
    myVector3.push_back(3);
    myVector3.insert(2, 6);
    myVector3.erase(3);
    myVector3.vectorSize();
    myVector3.empty();
    myVector1.empty();
    return 0;
}

