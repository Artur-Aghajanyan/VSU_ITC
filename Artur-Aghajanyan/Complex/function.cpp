#include <iostream>

/*
 *	Static Function
 *	name foo
 *	it is has one static member
 * */
int foo() {
	static int i = 0;
	++i;
	return i;
}

iint main() {
	/*
	 *	I call foo function 5 time
	 *	for the sixth time I print resalt
	 * */
	for(int i = 0; i < 5; ++i)
		foo();
	
	// sixth time for calling foo function
	std::cout << foo() << std::endl;\

	return 0;
}
