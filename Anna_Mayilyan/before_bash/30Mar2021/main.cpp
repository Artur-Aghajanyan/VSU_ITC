#include <iostream>
#include "func.h"

int main (){
    int x=10, i=0;
    while(i<x){
    int t = fib(i);
    std::cout<<t<<std::endl;
    i++;}
    int f = fact(x);
    std::cout<<f<<std::endl;
    return 0;
}

