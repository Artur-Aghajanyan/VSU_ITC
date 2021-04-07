#include <iostream>
#include "vector.h"

int main() {
    Vector v1;
    Vector v2(6);
    Vector v3(3, 666);
    Vector v4 = v3;

    std :: cout << "v3 = ";
    v3.print();
    std :: cout << "v4 = ";
    v4.print();

    std :: cout << "Empty ";
    std :: cout << v1.empty() << std :: endl;

    for(int i = 0; i < 6; ++i) {
        v1.pushBack(i + 1);
    }
    std :: cout << "Before popBack v2 = ";
    v1.print();
    std :: cout << std :: endl;
/*  
    v2.popBack();
    std :: cout << "After popBack v2 = ";
    v2.print();
    std :: cout << std :: endl;
    
    v2.insert(2, 666);
    std :: cout << "After insert function v2 = ";
    v2.print();
    std :: cout << std :: endl;
    
    std :: cout << "Empty " << v2.empty() << ' ';
    
    for(int i = 1; i <= v2.Size(); ++i) {
        std :: cout << v2[i];
    }
*/
    return 0;
}
~    
