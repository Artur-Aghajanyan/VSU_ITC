#include <iostream>

bool search(int *arr, int begin, int end, int num)
{
    while (begin <= end)
    {
        int mid = (end + begin) / 2;
        if (arr[mid] > num)
        {
            return search(arr, begin, mid - 1, num);
        }
        if (arr[mid] < num)
        {
            return search(arr, mid + 1, end, num);
        }
        return true;
    }
    return false;
}
  
int main(void)
{
    int array[20] = {1, 3, 5, 6, 7, 23, 34, 60, 78, 100, 101, 103, 105, 106, 107, 123, 134, 160, 178, 200};

    int number = 98;
    int size = 20;
    bool result = search(array, 0, size - 1, number);
    if (result)
    {
        std::cout << "Number  " << number << " is present in array";
        std::cout << std::endl;
    } else {
        std::cout << "Number  " << number << " is not present in array";
        std::cout << std::endl;
    }
    return 0;
}






