#include <iostream>

int search(int* arr,int first, int last, int el);

int main() {
    int el;
    int arr [20] = {1, 3, 5, 6, 7, 23, 34, 60, 78, 100, 101, 103, 105, 106, 107, 123, 134, 160, 178, 200};
    int size = 20;
    std::cout << "Enter digit to search: ";
    std::cin >> el;
    int k = search(arr, 0, size, el);
    std::cout << k << std::endl;
}

int search(int* arr,int first, int last, int el) {
    if(first == last && arr[first] != el) {
        std::cout << "there are no such value" << std::endl;
        return el;
    }
    int l = (last+first)/2;
    int middle = arr[(last+first)/2];
    if(middle == el) {
        return l;
    }

    else if(middle < el) {
        search(arr,l+1, last, el);
    }

    else {
        search(arr, first,l , el);
    }
}
