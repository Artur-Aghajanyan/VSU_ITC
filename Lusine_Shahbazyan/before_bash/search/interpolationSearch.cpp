#include <iostream>

int search(int *arr, int begin, int end, int num)
{
    if(begin <= end)
    {
        int mid = begin + (((double)(end - begin) / (arr[end] - arr[begin])) * (num - arr[begin]));
        if(mid < 0 || mid > end)
        {
            return -1;
        }
       
        else if(arr[mid] == num)
        {
            return mid;
        }
       
        else if (arr[mid] < num)
        {
            return search(arr, begin, mid - 1, num);
        }
       
       
        return search(arr, mid + 1, end, num);
    }
    return -1;
}
 
int main(void)
{
    int array[20] = {1, 3, 5, 6, 7, 10, 12, 15, 18, 20, 23, 25, 27, 29, 30, 32, 35, 38, 39, 40};

    int number = 22;
    int size = 20;
    int result = search(array, 0, size - 1, number);
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


