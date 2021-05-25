#include <iostream>
#include "list.h"

int main (){
List<int> l;
l.push(15);
l.push(1);
l.push(11);
l.push(5);
l.print();
std::cout<<std::endl;
//l.pop();
//l.print();
//l.erase(1);
//l.print();
//l.insert(2,7);
//l.print();

return 0;
}

