#include <iostream>

int ternarySearch(int left, int right, int num, int* arr)
{
    if (right >= left)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == num)
        {
            return mid1;
        }
        if (arr[mid2] == num)
        {
            return mid2;
        }
 
        if (num < arr[mid1])
        {
            return ternarySearch(left, mid1 - 1, num, arr);
        }
        else if (num > arr[mid2])
        {
            return ternarySearch(mid2 + 1, right, num, arr);
        }
        else 
        {
            return ternarySearch(mid1 + 1, mid2 - 1, num, arr);
        }
    }
    return -1;
}
 
int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int left = 0;
    int right = 9;
    int numberForSearch = 5;
    int index = ternarySearch(left, right, numberForSearch, array);
    if(index == -1)
        std::cout << "Number  " << numberForSearch << " is not present in array "<< std::endl;
    else
        std::cout << "Number  " << numberForSearch << " is in  index  " << index << std::endl;
        
}

