#include "functions.h"

double mean(int *array, int s) {
	int sum = 0;
	double mean;
	
	for(int i = 1; i <= s; ++i) {
		sum += array[i];
	}
	
	mean = (double) sum / s;
	return mean;
}
