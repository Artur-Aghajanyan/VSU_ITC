#include <iostream>

void build(int n)
{
	int f[n];
	f[0] = 2;
	f[1] = 3;
	int a;
	for(int i = 2; i < n; ++i){
		f[i] = f[i-1] + f[i-2];
		a = f[i];
	}
std::cout<<a*a;
}

int main () 
{
	int n;
	std::cout<<"n= ";
	std::cin>>n;
	std::cout<<"Buildind will be constracted in ways ";
	build(n);
	return 0;
}
