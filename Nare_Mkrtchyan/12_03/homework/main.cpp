#include <iostream>
#include "itc_string.h"
int main(){
    const char* x="asd";
    itc::string s(x);

//    string s(x);
    s.print();
    std::cout<<"This is an object"<<std::endl<<s<<std::endl;

   return 0;
}
