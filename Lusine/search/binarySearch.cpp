#include <iostream>

int binarySearch(int *arr, int begin, int end, int num)
{
    if(begin <= end)
    {
        int mid = (end + begin) / 2;
        if(arr[mid] == num)
        {
            return mid;
        }
       
        else if (arr[mid] > num)
        {
            return binarySearch(arr, begin, mid - 1, num);
        }
        return binarySearch(arr, mid + 1, end, num);
    }
    return -1;
}
 
int main(void)
{
    int array[20] = {1, 3, 5, 6, 7, 23, 34, 60, 78, 100, 101, 103, 105, 106, 107, 123, 134, 160, 178, 200};

    int number = 103;
    int size = 20;
    int result = binarySearch(array, 0, size - 1, number);
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


