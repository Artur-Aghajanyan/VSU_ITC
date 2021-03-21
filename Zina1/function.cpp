/*
    Gives the count of calls of print() function
*/ 
print() {
	static int x = 0;
	++x;
	return x;
}
