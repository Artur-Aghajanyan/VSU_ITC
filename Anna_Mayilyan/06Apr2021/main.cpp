#include <iostream>
#include "stack.h"

int main(){
Stack<int> o, o1;
o.push(1);
o.push(3);
o1.push(7);
o1.push(11);
o1.push(12);
o.swap(o1);
std::cout<<o.Size()<<std::endl;
o.pop();
std::cout<<o.Size()<<std::endl;
if(o.empty() == 0)
o.push(77);
else
std::cout<<"Is not empty";
return 0;
}
