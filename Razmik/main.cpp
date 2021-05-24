#include <iostream>
#include "string.h"

int main() {
	array<std::string> object;
	object.push("I see skies of blue");
	object.push("and clouds of white");
	object.push("And i think to myself for a wonderful world");
	object.print();
	
	return 0;
}
