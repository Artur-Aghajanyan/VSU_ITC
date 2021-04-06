#include <iostream>
#include "itc_string.h"

int main(){
    const char* x="asd";
    itc::string s(x);
    s.print();

   return 0;
}
