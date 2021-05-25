#include <iostream>
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int *arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[right]);
    return (i + 1);
}
 
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, left + 1, right);
    }
}

int main()
{
    int size = 20;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = random() % 50;
    }
    quickSort(array, 0, size - 1);
    for(int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    return 0;
}
