#include <iostream>
#include "complex.h"

int main ()
{
    Complex<int> c1(2,1), c2(1,4),c3, c5;
    // std::cin>>c1;
    //std::cin>>c2;
    c3=c1*c2;
    Complex<int> c4(c3);//calls copy constructor
    c5=c1+c4;
    std::cout<<c1+c2<<std::endl;
    std::cout<<c1-c2<<std::endl;
    std::cout<<c3<<std::endl;
    std::cout<<c5<<std::endl;
    //count will show how many times parametrized costructor was called
    std::cout<<Complex<int>::count<<std::endl;
    Complex<float> c6(2.5, 3.5), c7(1.6, 2.7);
    std::cout<<c6+c7<<std::endl;
    return 0;
}


