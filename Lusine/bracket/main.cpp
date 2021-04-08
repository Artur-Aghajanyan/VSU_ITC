#include <iostream>
#include <string>
#include "bracket.h"

void chack(std::string  arr, int n,Stack st)
{
    bool istrue = true;
    int index = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        { 
            index = i; 
            st.push(arr[i]);
        } else if(arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if(arr[i] - st.top() == 1 ||  arr[i] - st.top() == 2)
            {
                st.pop();
            }else{
                index = i;
                std::cout << "index = " << index <<std::endl;
                break;
            }
        }
    }
    if(st.empty())
    {
        std::cout << "There is no error" << std::endl;
    } else {
        std::cout << "index = " << index <<std::endl;
    }
}

int main() 
{
    std::string myString;
    std::cout << "Please enter string for checking : ";
    std::cin>> myString;
    int n = myString.length();
    Stack st(n);
    chack(myString, n, st);
}


