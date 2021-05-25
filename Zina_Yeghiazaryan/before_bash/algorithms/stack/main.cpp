#include <iostream>
#include "template.h"

int main() {
	Stack <int> s;
	
	std :: cout << "Empty " << s.empty() << std :: endl;
	
	for(int i = 1; i < 7; ++i) {
		s.push(i);
	}
	
	s.pop()
	std :: cout << "Poped the last element of Stack - " << s.top() << std :: endl;
	std :: cout << "Size of s - " << s.Size() << std :: endl;
	std :: cout << "The top of s - " << s.top() << std :: endl;
	
	Stack <int> s1;
	Stack <int> s2;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s2.push(40);
	s2.push(50);
	
	s2.swap(s1);
	std :: cout << "Size of s1 - " << s1.Size() << std :: endl;
	std :: cout << "Size of s2 - " << s2.Size() << std :: endl;
	
	return 0;
}
