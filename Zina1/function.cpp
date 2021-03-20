#include "complex.h"

/*
    Gives the count of calls of print() function
*/ 
int Complex :: print() {
	static int x = 0;
	++x;
	return x;
}

/*
    Set function for real part of complex number
*/
void Complex :: setReal(int r) {
    real = r;
}

/*
    Set function for imagenary part of complex number
*/
void Complex :: setImage(int i) {
    image = i;
}

/*
    Get function for real part of complex number
*/
int Complex :: getReal() {
    return real;
}

/*
    Get function for imagenary part of complex number
*/
int Complex :: getImage() {
    return image;
}
