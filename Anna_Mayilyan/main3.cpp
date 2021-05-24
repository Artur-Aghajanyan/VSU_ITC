#include <iostream>
#include "list1.h"

int main (){
List<int> l;
l.push(15);
l.push(1);
l.push(11);
l.push(5);
l.print();
std::cout<<std::endl;
std::cout<<l[0]<<std::endl;
//l.pop();
//l.print();
//l.erase(1);
//l.print();
//l.insert(1,7);
//l.print();

return 0;
}
