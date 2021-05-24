#include <iostream>
int count = 0;
int* quick_sort(int* arr, int l, int r, int s);
int main() {
    int arr[] = {5,26,1,3,9,12,4,7,66,2};
    int msize = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, msize-1, -1);
    for(int i = 0; i < msize; ++i) {
        std::cout << arr[i] << " ";
    }  
    std::cout << std::endl;
    std::cout << "count: " << count << std::endl;
    return 0;
}


int* quick_sort(int* arr, int l, int r, int s) {
    int pivot = arr[r];
    int helper, h2;
    int size = r - l + 1;
    int j = l;
    int i = s; 
    if(l >= r) {
        return  arr;
    }
    while(j < l+size-1) {
        if(arr[j] < pivot) {
            ++i;
            helper = arr[i];
            arr[i] = arr[j];
            arr[j] = helper;
            ++j;
        }
        else {
            ++j;
        }
        ++count;
    }  
    helper = arr[i+1];
    arr[i+1] = pivot;
    for(int k = i+2; k < r+1; ++k) {
        h2 = arr[k];
        arr[k] = helper;
        helper = h2;
    }
    
    quick_sort(arr, l, i, l-1);
    if(i+2<=r) {
        quick_sort(arr, i+2, r,i+1);
    }
}
