#include <iostream>
#include "stack.h"

void checkingString(std::string str) {
	Stack<char> s(10);
	int index;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str[i]);
			index = i;
		}
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if(s.top() == '(' && str[i] == ')' )
				s.pop();
			else if(s.top() == '{' && str[i] == '}')
				s.pop();
			else if(s.top() == '[' && str[i] == ']')
				s.pop();
			else {
				std::cout << "Error in index - " << i << std::endl;
				return;
			}
		}		
	}
	if(s.top() == '(' || s.top() == '{' || s.top() == '[') {
		std::cout << "Error in index - " << index << std::endl;
		return;
	}

	if(s.empty())
		std::cout << "There is not Error, Very Nice\n";	
}

int main() {
	std::string str;
	std::cout << "Write String for checking: ";
	std::cin >> str;
	
	checkingString(str);

	return 0;
}
