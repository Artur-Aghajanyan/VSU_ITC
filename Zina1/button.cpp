#include <iostream>
#include "button.h"

Button :: Button () {
	width = 0;
	height = 0;
}

Button :: Button (int width, int height) {
	this -> width = width;
	this -> height = height;
}

Button :: Button (int x, int y, std :: string color, int w, int h) : View (x, y, color) {
       	width = w;
	height = h;
}

void Button :: setWidth(int w) {
	width = w;
}

void Button :: setHeight(int h) {
        height = h;
}

int Button :: getWidth() {
	return width;
}

int Button :: getHeight() {
        return height;
}
void Button :: print() {
	View :: print();
	std :: cout << width << ' ' << height << ' ';
}
