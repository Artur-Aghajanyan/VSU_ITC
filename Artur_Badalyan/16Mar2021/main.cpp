#include <iostream>
#include "list.h"

int main() {
	
		List<std::string> o;

		o.push("Text1");
		o.push("Text2");
		o.push("Text3");
		o.push("Text4");
		o.push("Text5");

		o.printList();
		std::cout << "\n";
		o.pop();
		std::cout << "---- pop ----\n";
		o.printList();		
		std::cout << std::endl;
		std::cout << "---- erase ----\n";
		o.erase(2);
		std::cout << std::endl;
		o.printList();
		std::cout << "\n---- insert ----\n";
		o.insert(3,"insert");
		o.printList();
		std::cout << "\n---- operator ----\n";
		std::cout <<  o[2] << std::endl;



	return 0;
}
