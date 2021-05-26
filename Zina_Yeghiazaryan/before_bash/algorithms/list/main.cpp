#include <iostream>
#include "list.h"

int main() {
	List<int> l;
	l.push(4);
	l.push(5);
	l.insert(1,7);
	l.erase(1);
	std :: cout << "Print the list \n";
	l.print();
	l.push(6);
	l.push(3);
	l.pop();
	std :: cout << "Print the list after some changes\n";
	l.print();
	std :: cout << "The size of list is - " << l.Size() << std :: endl;
	std :: cout << "The top of list is - " << l.top() << std :: endl;
	return 0;
}
