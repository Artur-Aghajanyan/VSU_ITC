#include <iostream>
#include "Nare.h"

int darr(int *a, int x);

int main(){
	int n,m,x;
	std::cout<<"array length="; std::cin>>x;
	int *a=new int[x];
	
	for(int i=0; i<x;i++){
		std::cout<<"a["<<i<<"]=";std::cin>>a[i];	
	}

	std::cout<<"number for factorial = ";std::cin>>n;
	std::cout<<"number for fibonachi = ";std::cin>>m;
	std::cout<<"factorial("<<n<<")="<<fac(n)<<std::endl;
	std::cout<<"fibonachi("<<m<<")="<<fibonachi(m)<<std::endl;

	std::cout<<"The arithmetical average = "<<darr(a,x)<<std::endl;
	return 0;
	
}

int darr(int *a, int x){
	int k=0;
	for(int i=0; i<x;i++){
	k=k+a[i];
	}
	return k/x;
}
