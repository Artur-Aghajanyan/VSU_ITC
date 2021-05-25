#include <iostream>
#include "complex.h"

int Complex::count=0;
int main ()
{
    Complex c1(2,1), c2(1,4),c3, c5;
    // std::cin>>c1;
    //std::cin>>c2;
    c3=c1*c2;
    Complex c4(c3);//calls copy constructor
    c5=c2+c4;
    std::cout<<c1+c2<<std::endl;
    std::cout<<c1-c2<<std::endl;
    std::cout<<c3<<std::endl;
    std::cout<<c5<<std::endl;
    //count will show how many times parametrized costructor was called
    std::cout<<Complex::count<<std::endl;
    return 0;
}

