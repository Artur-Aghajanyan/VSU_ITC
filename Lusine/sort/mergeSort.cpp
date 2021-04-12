#include <iostream>

void merge(int arr[], int left, int mid, int right) 
{ 
  int size1 = mid - left + 1; 
  int size2 = right - mid; 
  int *LEFT = new int[size1];
  int *RIGHT = new int[size2]; 
  for (int i = 0; i < size1; i++) 
  {
    LEFT[i] = arr[left + i];
  }
  for (int j = 0; j < size2; j++) 
  {
    RIGHT[j] = arr[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = left;
  while (i < size1 && j < size2) 
  { 
    if (LEFT[i] <= RIGHT[j]) 
    { 
      arr[k] = LEFT[i]; 
      i++; 
    } else { 
        arr[k] = RIGHT[j]; 
        j++; 
    } 
    k++; 
  } 
  while (i < size1) 
  { 
    arr[k] = LEFT[i]; 
    i++; 
    k++; 
  } 
  while (j < size2) 
  { 
    arr[k] = RIGHT[j]; 
    j++; 
    k++; 
  }
  delete [] LEFT;
  delete [] RIGHT; 
} 

void mergeSort(int arr[], int left, int right) 
{ 
  if (left < right)
  {  
    int mid = left + (right - left) / 2; 
    mergeSort(arr, left, mid); 
    mergeSort(arr, mid + 1, right); 
    merge(arr, left, mid, right); 
  } 
} 

void printArray(int arr[], int size)
 { 
  for (int i = 0; i < size; i++)
  { 
    std::cout << arr[i] << " "; 
  }
  std::cout << "\n";
} 
  
int main()
{ 
  int array[] = {2, 51, 23, 65, 6, 87, 90, 8 };
  int size = sizeof(array) / sizeof(array[0]); 
  printArray(array, size); 
  mergeSort(array, 0, size - 1); 
  std::cout << "\nSorted array\n";
  printArray(array, size); 
} 
