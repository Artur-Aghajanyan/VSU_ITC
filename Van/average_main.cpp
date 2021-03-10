#include <iostream>

void func(int* arr, int n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
                sum += arr[i];
        }
        std::cout << "average = " << sum/n << std::endl;
}

int main() {
        int n;
        int * arr;
        std::cout << "Nermuceq erkarutyun@\n";
        std::cin >> n;
        arr = new int[n];
        for (int i = 0; i<n; i++) {
                std::cout << "arr[" << i << "] = ";
                std::cin >> arr[i];
        }
        func(arr, n);
        return 0;
};
