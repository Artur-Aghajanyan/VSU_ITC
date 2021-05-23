#include <iostream>
#include "Fact.h"
using namespace std;

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else
    {
        cout << print_fact(n) << "\n";
    }
}

