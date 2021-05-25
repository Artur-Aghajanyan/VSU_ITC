#include <iostream>
#include <cmath>

int pos_ways1(int n);
int pos_ways2(int n);
int main() {
    int n;
    std::cout << "Number of sections': ";
    std::cin >> n;
    std::cout << "Possible ways to place buildings (first way): " << pos_ways1(n) << std::endl;
    std::cout << "Possible ways to place buildings(second way): " << pos_ways2(n) << std::endl;
    
    return 0;

}
int pos_ways1(int n) {
    int arr[n];
    arr[0] = 2;
    arr[1] = 3;
    for(int i = 2; i < n;++i ) {
        arr[i] = arr[i-2] + arr[i - 1];
    }
    return arr[n-1]*arr[n-1];
}

int pos_ways2(int n) {
    
    int found = round(pow(((1+sqrt(5))/2),n+2)/sqrt(5));
    return found*found;
}
