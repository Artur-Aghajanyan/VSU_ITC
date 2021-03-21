#include <iostream>
#include "complex.h"


int main(){
        


		Complex obj1(5,4);
		Complex obj2(4,5);
	    Complex result1;
        Complex result2;       
 		Complex result3;
        
        std :: cin  >> obj1 >> obj2;
		result1 = obj1 + obj2;
		result2 = obj1 - obj2;
		result3 = obj1 * obj2;
        std :: cout << result1 << std :: endl;
		std :: cout << result2 << std :: endl;
		std :: cout << result3 << std :: endl;






		return 0;
}	
