#include "anna.h"
int fib(int n){
	if((n==1) || (n==0))
		return n;
		else
			return(fib(n-1)+fib(n-2));
	}

int fact(int n){
	if(n>1)
		return n*fact(n-1);
	else
		return 1;
}

float average(int *array, int n) {
float sum=0;
	for(int i=0; i<n; i++){
		sum=sum+array[i];
	}
	
	return (sum/n);
}
