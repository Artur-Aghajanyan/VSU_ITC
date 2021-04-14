#include <iostream>
#include <math.h>

int linerSearch(int *arr, int begin, int end, int number)
{
    for(int i = begin; i <= end; ++i)
    {
        if(arr[i] == number)
            return i;
    }
    return -1;
}

int jumpSearch(int *arr, int size, int number)
{
    if(number < arr[0] || number > arr[size])
        return -1;
    int i = 0;
    int jump = sqrt(size);
    while (i < size && arr[i] <= number)
    {
        i += jump;
    }
        linerSearch(arr, i - jump, std::min(i, size), number);
}
 
int main(void)
{
    int array[10] = {1,2,3,4,5,6,6,8,9,10};
    int number = 9;
    int arraySize = 10;
    int result = jumpSearch(array, arraySize - 1, number);
   
    if (result == -1)
    {
        std::cout << "Number " << number << " is not present in array";
        std::cout << std::endl;
    } else {
        std::cout << "Number " << number << " is present in index " << result;
        std::cout << std::endl;
    }
    return 0;
}
