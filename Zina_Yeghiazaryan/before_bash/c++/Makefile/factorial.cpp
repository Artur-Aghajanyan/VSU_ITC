#include "functions.h"

int fact(int n) {
	if(n == 0) {
		return 1;
	}
	
	if(n == 1) {
		return 1;
	}
	
	if(n > 1) {
		int k = 1;
		
		for(int i = 1; i <= n; ++i) {
			k *= i;
		}
		return k;
	}
}
