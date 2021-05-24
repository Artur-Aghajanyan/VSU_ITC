#include "anna.h"

int main (){
	int x=10, i=0;
	while(i<x){
	std::cout<<fib(i)<<std::endl;
	i++;}

	std::cout<<fact(x)<<std::endl;
	std::cout<<"\n";
        int n;
	std::cout<<"n="; std::cin>>n;
	int  *array=new int[n];
	for(i=0; i<n;i++){
		std::cin>>array[i];}
	std::cout<<"average="<<average(array,n)<<std::endl;
	return 0;
}
