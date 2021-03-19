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
