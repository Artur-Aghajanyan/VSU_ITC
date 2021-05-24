#include<iostream>
    int main() {
    	int n,a=1;
    	std::cout<<" nermuceq n tiv:  ";
    	std::cin>>n;
    	for (int i=1;i<=n;i++) {
    		a=a*i;
    	}
    	std::cout<<n <<"!="<<a<<std::endl;
    	return 0;
    }
