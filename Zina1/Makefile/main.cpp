#include <iostream>
#include <iomanip>
#include "functions.h"

int main() {
	int n;
	std :: cin >> n;
	std :: cout << "fibonacci number = " << fib(n);
	std :: cout << std :: endl;
	std :: cout << "factorial = " << fact(n);
	
	int s;
	std :: cin >> s;
	int *a = new int[s];
	for(int i = 1; i <= s; ++i) {
		std :: cin >> a[i];
	}
	std :: cout << std :: setprecision(3) << setiosflags(std :: ios :: fixed | std :: ios :: showpoint) << mean(a, s);
}
