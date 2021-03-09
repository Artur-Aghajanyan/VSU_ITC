#include <iostream>
#include "header.h"

int main() {
    int tmp;
    std :: cout << "Please enter an integer greater than 0 to count that factorial number ::  ";
    std :: cin >> tmp;
    std :: cout << "will be the number of that factorial number :: " << factorial(tmp) << std :: endl;

    // fibonachi series 1 1 2 3 5 8 13 21 34 55 89 144 233 377
    std :: cout << "Please enter an integer greater than 0 to count that fibonachi number ::  ";
    std :: cin >> tmp;
    std :: cout << "will be the number of that fibonachi number :: " << fib(tmp) << std :: endl;

    std :: cout << "Please enter array size ::  ";
    std :: cin >> tmp;
    int* arr = new int[tmp];
    for(int i = 0; i < tmp; ++i) {
        std :: cout << "arr[" << i << "] = ";
        std :: cin >> arr[i];
    }
    std :: cout << "will be the arithmetic mean of the numbers entered :: " << arithmetic_mean(tmp, arr) << std :: endl;
}