#include <iostream>

int fac(int n){
	int s=1;
	for(int i=1; i<=n; i++){
	s=s*i;
	}
return s;
}

int fibonachi(int m){
	int a1=0, a2=1, a3;
	if(m==0) return a1;
	else if(m==1) return a2;
	else for(int i=2;i<m;i++){
		a3=a1+a2;
		a1=a2;a2=a3;
	} return a3;
}
