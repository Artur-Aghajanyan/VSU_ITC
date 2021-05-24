#include <iostream>

int fib (int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n > 1) {
		int f1 = 0, f2 = 1, k;
		for (int i = 1; i < n; i++) {
			k = f1 + f2;
			f1 = f2;
			f2 = k;
		}
		return k;
	}
}

int fact (int n) {
	int k;
	if (n == 0 || n == 1) return 1;
	if (n > 1) {
	        k = 1;
		for (int i = 1; i <= n; i++) {
			k *= i;
		}
		return k;
	}
}
/*int main () {
	return 0;
}*/
