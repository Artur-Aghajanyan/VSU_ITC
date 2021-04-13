#include <iostream>

void insert(int* arr, int size);

int main() {
    int arr[] = {5, 12, 9, 56, 32, 13, 22, 33, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before: " << std::endl;
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insert(arr, size);

    std::cout << "After: " << std::endl;
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insert(arr, size);
    return 0;
}

void insert(int* arr, int size) {
    int el, el1;
    for(int j = 1; j < size; ++j) {
        int i = j - 1;
        while(arr[j] < arr[i] ) {
            if(i > 0) {
                if(arr[j] < arr[i - 1]) {
                    --i;
                }
                else {
                    el1 = arr[j];
                    for(int c = i; c < j + 1; ++c) {
                        el = arr[c];
                        arr[c] = el1;
                        el1 = el;

                    }
                    break;
                }
            }
            else {
                break;
            }
        }
        continue;
    }
}
