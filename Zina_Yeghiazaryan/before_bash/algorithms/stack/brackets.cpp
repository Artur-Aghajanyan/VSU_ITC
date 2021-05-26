#include <iostream>
#include <string>
#include "template.h"

int main() {
	Stack <char> s;
	std :: string a;
	std :: cout << "Input the text - ";
	std :: cin >> a;
	int k = 0;
	
	if(a.length() > 1) {
		for (int i = 0; i < a.length(); i++) {
    		if (a[i] == '(' || a[i] == '{' || a[i] == '[') {
        	   s.push (a[i]);
        	} else if (a[i] == ')') {
        		if (s.top() == '(') {
            	    s.pop();
	            } else {
	            	std :: cout << "Error! " << i << std :: endl;
	            	break;
				}
	        } else if (a[i] == '}') {
	        	if (s.top() == '{') {
	                s.pop();
	            } else {
	            	std :: cout << "Error! " << i << std :: endl;
	            	break;
				}
	        } else if (a[i] == ']') {
	            if (s.top() == '[') {
	                s.pop();
	            } else {
	            	std :: cout << "Error! " << i << std :: endl;
	            	break;
				}
	        }
	    }
	} else {
		k++;
		std :: cout << "Error! The number of elements is not enough!" << std :: endl;
	}
	
	if(s.empty() == true && k == 0) {
		std :: cout << "true";
	} else {
		std :: cout << "false";
	}
	return 0;
}
