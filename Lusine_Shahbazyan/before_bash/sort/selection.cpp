#include <iostream>

void sort(int *arr, int n)
{
    int  count = 0;
    for(int j = 0; j < n - 1; ++j)
    {
        int index = j;
        for(int i = j + 1; i < n; i++)
        {
            ++count;
            if(arr[i] < arr[index])
            {
                index  = i;
            }
        }
        int temp = arr[j];
        arr[j] = arr[index];
        arr[index] = temp;
    }

    std::cout << std::endl;
    std::cout << count;
    std::cout << std::endl;

}

int main(void)
{
    int array[6] = {13, 11, 4, 36, 45, 52};
    int number = 201;
    int size = 6;
    sort(array, size);
    for(int i = 0; i < size ; i++)
        {
           std::cout << array[i] << " ";
        }
    std::cout << std::endl;
    return 0;
}

