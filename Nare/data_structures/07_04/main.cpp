#include <iostream>
#include "list.h"

int main() {
    List<int> l;
    l.push_front(1);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(7);
    l.push_front(1);
    l.push_front(1);
    
    l.insert(3,55);
    l.erase(3);

    if(!l.empty()) {
        l.pop_front();
        l.pop_back();
    }
    std::cout << "size: " << l.Size() << std::endl;
    l.print();
    return 0;

}
