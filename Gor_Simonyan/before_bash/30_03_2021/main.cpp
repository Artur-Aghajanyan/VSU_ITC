#include <stdio.h>
#include "func.h"

int main()
{
	int s = sum(10,23);
	int d = dif(7,5);
	int mx = max(8,-2);
	int mn = min(-3,-1);
	printf("sum = %d\ndif = %d\nmax = %d\nmin = %d\n",s,d,mx,mn);
}
