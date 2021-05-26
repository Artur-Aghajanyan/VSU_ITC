#include <iostream>

void merge_sort(int* arr, int l, int m, int r);
void divide(int* arr, int l, int r);

int main() {
    int arr[] = {2, 5, 31, 66, 4, 15, 3, 98, 45, 56, 12, 77};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    divide(arr, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void divide(int* arr, int l, int r) {
    if(l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    divide(arr, l, mid);
    divide(arr, mid + 1, r);
    merge_sort(arr, l, mid , r);
}

void merge_sort(int* arr, int l, int m, int r) {
    int s1 = m - l + 1;
    int s2 = r - m ;
    int a1[s1];
    int a2[s2];

    for(int i = 0 ; i < s1; ++i) {
        a1[i] = arr[l+i];
    }

    for(int j = 0; j < s2; ++j) {
        a2[j] = arr[m + j + 1];
    }
    
    int i = 0;
   int  j = 0;
    int k = l;
    while(i < s1 && j < s2) {
        if(a1[i] > a2[j]) {
            arr[k] = a2[j];
            ++j;
        }
        else {
            arr[k] = a1[i];
            ++i;
        }
        ++k;
    }

    while(i < s1) {
        arr[k] = a1[i];
        ++i;
        ++k;
    }

    while(j < s2) {
        arr[k] = a2[j];
        ++j;
        ++k;
    }
}

