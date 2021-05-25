#include <iostream>
#include <cmath>

using namespace std;

int fib(int number)
{
    int arr[number];
    if(number == 1)
    {   
        return 0;
    }   
    if(number == 2)
    {   
        return 1;
    }   
    else
    {   
        arr[0] = 0;
        arr[1] = 1;
        int sum;
        for(int i = 2; i < number; i++)
        {
            sum = arr[i-2]+arr[i-1];
            arr[i] = sum;
        }
        return sum;
    }   
}


int CPW(int number)
{
    return pow(fib(number+3),2);    
}

int main()
{
    cout<<CPW(4)<<endl;
    return 0;
}
