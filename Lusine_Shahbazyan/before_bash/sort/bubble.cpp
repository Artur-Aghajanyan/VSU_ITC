#include <iostream>

void sort(int *arr, int n)
{
    int  count = 0;

    for(int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for(int j = 0; j < n - i - 1  ; j++)
        {

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
                ++count;
            }
        }
        if(flag == true)
        break;
    }
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << "   ";
    }
    std::cout << std::endl;
    std::cout << count;
    std::cout << std::endl;
}

int main(void)
{
    int array[6] = {300, 11, 24, 36, 45, 52};
    int number = 201;
    int size = 6;
    for(int i = 0; i < size; ++i)
    {
        std::cout << array[i] << "   ";
    }
    std::cout << std::endl;
    sort(array, size);
    return 0;
}

