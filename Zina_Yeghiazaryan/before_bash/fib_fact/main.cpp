#include <iomanip>
#include "fib_fact.h"
#include <iostream>

double meannum (int *array, int s) {
        int sum = 0;
        double mean1;
        for (int i = 0; i < s; i++) {
                sum += array[i];
        }
        mean1 = (double) sum / s;
        return mean1;
}

int main () {
	int n;
	std :: cin >> n;
	std :: cout << "fibonacci number = " << fib (n) << "\nfactorial = " << fact (n);
	int s;
	std :: cin >> s;
	int *a = new int [s];
	for (int i = 0; i < s; i++) {
		std :: cin >> a[i];
	}
	std :: cout << std :: setprecision (2) << setiosflags (std :: ios :: fixed | std :: ios :: showpoint) << meannum(a, s) << "\n";
}
