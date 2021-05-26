#include <iostream>

int main()
{
    int size = 20;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = random() % 100;
    }
    for (int i = 1; i < size; ++i) 
    {
        int temp = array[i]; 
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {  
            array[j + 1] = array[j];  
            --j;
        }  
        array[j + 1] = temp;  
    }  
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i]<< " ";
    }
}
