#include "functions.h"

int fib(int n) {
	if(n == 0) {
		return 0;
	}
	
	if(n == 1) {
		return 1;
	}
	
	if(n > 1) {
		int f1 = 0, f2 = 1, k;
		
		for(int i = 1; i <= n; ++i) {
			k = f1 + f2;
			f1 = f2;
			f2 = k;
		}
		return k;
	}
}
