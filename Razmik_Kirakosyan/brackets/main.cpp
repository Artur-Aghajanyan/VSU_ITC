#include <iostream>
#include "stack.h"


int main() {
	Stack obj;
	std :: string data = "(gbalge{{{})lbgd"; 
	for (int i = 0; i < data.length(); ++i) {
		if (data[i] == '(' || data[i] == '[' ||data[i] == '{' ) {
			obj.push(data[i]);
	} 
	else if	(data[i] == ')' || data[i] == ']' || data[i] == '}' ) {
		if (!obj.check(data[i])) {
			std :: cout << data[i] << std :: endl ;
        return 0;	
		}		
			
        }
	
	
	
	}
	if (!obj.check_array()) {
		std :: cout << "Closing brackets are more than opening brackets" << std :: endl;
		return 0;
	}
	return 0;
}

