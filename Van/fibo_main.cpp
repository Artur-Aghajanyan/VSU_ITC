#include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, a = 0;

    cout << "nermuceq tiv: ";
    cin >> n;

   for (int i = 0; i <= n; ++i) {
        if(i == 0) {
            continue;
        }
        if(i ==2) {
            continue;
        }
        a = t1 + t2;
        t1 = t2;
        t2 = a;
    } cout << "Fibonacci = "<<a <<endl;
    
    return 0;
}
