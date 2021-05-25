#include <iostream>
#include "vector.h"

int main() {
  //  Vector v;
    Vector<int> v(5, 10);
    v.push_back(16);
    v.push_back(15);
    Vector<int> cv = v;
    v.print();
    v.pop_back();
    if(v.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } 
    else {
        v.print();
    }
   // v.insert(3, 105);
   v.insert(3, 3, 11);
   std::cout << "v's size is: " << v.fsize() << std::endl;
   std::cout << "v[5] = " << v[5] << std::endl;
    v.print();
    cv.print();
    std::cout << std::endl;
    return 0;
}
