#include <iostream>
#include "list.h"

int main () {
    List<int> list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.pop();
    list.ibase(2);
    list.insert(2,5);
    std :: cout << list[2] << std :: endl;
    list.print();
    return 0;
}
