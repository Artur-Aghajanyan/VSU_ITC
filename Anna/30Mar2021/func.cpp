#include "func.h"
int fib(int n){
    if((n==1) || (n==0))
        return n;
        else
            return(fib(n-1)+fib(n-2));
    }

int fact(int n){
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}

