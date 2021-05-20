#include <iostream>

int print_fib(int i)
{
    if(i < 1) return 0;
    if(i ==1) return 1;
    return print_fib(i - 1) + print_fib(i - 2);
}


