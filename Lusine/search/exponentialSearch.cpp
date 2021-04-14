#include <iostream>

int binarySearch(int *arr, int begin, int end, int number)
{
    if(begin <= end)
    {
        int mid = (end + begin) / 2;
        if(arr[mid] == number)
        {
            return mid;
        }
        else if (arr[mid] > number)
        {
            return binarySearch(arr, begin, mid - 1, number);
        }
        return binarySearch(arr, mid + 1, end, number);
    }
    return -1;
}

int exponentialSearch(int *arr, int size, int number)
{
    if (arr[0] == number)
    {
        return 0;
    }
    int expJump = 1;
    while (expJump < size && arr[expJump] <= number)
        expJump *= 2;
        return binarySearch(arr, expJump/2, std::min(expJump, size - 1), number);
}
 
int main(void)
{
    int array[20] = {1, 3, 5, 6, 7, 10, 12, 15, 18, 20, 23, 25, 27, 29, 30, 32, 35, 38, 39, 40};
    int number = 103;
    int arraySize = 20;
    int result = exponentialSearch(array, arraySize, number);
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