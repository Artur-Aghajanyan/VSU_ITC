#include <iostream>

void sort(int *arr, int n, std::string a, std::string b)
{
    if(a == "asc")
    {
        if(b == "max")
        {
            for(int j = 0; j < n - 1; ++j)
            {
                int index = j;
                for(int i = j + 1; i < n; i++)
                {
                    if(arr[i] < arr[index])
                    {
                        index  = i;
                    }
                }
                int temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp;
            }
        } else {
            for(int j = n - 1; j > 0; --j)
            {
                int index = j;
                for(int i = j - 1; i >= 0; --i)
                {
                    if(arr[index] < arr[i])
                    {
                        index  = i;
                    }
                }
                int temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp;
            }        
        }

    } else {
        if(b == "min")
        {
            for(int j = 0; j < n - 1; ++j)
            {
                int index = j;
                for(int i = j + 1; i < n; i++)
                {
                    if(arr[i] > arr[index])
                    {
                        index  = i;
                    }
                }
                int temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp;
            }
        } else {
            for(int j = n - 1; j > 0; --j)
            {
                int index = j;
                for(int i = j - 1; i >= 0; --i)
                {
                    if(arr[index] > arr[i])
                    {
                        index  = i;
                    }
                }
                int temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp;
            }        
        }
    }
}

int main(void)
{
    int array[6] = {13, 11, 4, 36, 45, 52};
    int number = 201;
    int size = 6;
    sort(array, size, "desc", "max");
    for(int i = 0; i < size ; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
    return 0;
} 
