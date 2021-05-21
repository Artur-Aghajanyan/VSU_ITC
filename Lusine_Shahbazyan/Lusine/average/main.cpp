#include <iostream>
#include "Average.h"
using namespace std;

int main()
{
   int  n;
    cout << "Enter a positive integer: ";
    cin >> n;
    int* array = new int [n];
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << print_average(array, n) << "\n";
    delete [] array;
}

