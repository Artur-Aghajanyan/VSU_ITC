#include <iostream>
#include "list.h"

int main(){
    List<int> obj;
    obj.push(11);
    obj.push(16);
    obj.push(15);
    obj.push(18);
    obj.push(3);
    obj.push(4);

    obj.print();
    
    std::cout<<std::endl;
    std::cout<<obj[3]<<std::endl;
    std::cout<<obj[0]<<std::endl;
    std::cout<<obj[5]<<std::endl;
    std::cout<<obj[6]<<std::endl;
    
//    obj.pop();
//    obj.erase(0);
//    obj.insert(3,121212);
//    obj.insert(0,121212);
//    obj.insert(1,121212);
//    obj.print();
return 0;

}
