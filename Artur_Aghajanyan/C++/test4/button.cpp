#include <iostream>
#include "view.h"
#include "button.h"

Button::Button(){
	this->width = 0;
	this->height = 0;
}

Button::Button(int w, int h){
	this->width = w;
	this->height = h;
}
Button::Button(int x1, int y1, int w, int h):View(x1, y1){
	this->width = w;
	this->height = h;
}

int Button::getW(){
	return width;
}
int Button::getH(){
	return height;
}

void Button::setW(int w){
	this->width = w;
}
void Button::setH(int h){
	this->height = h;
}
void Button::print(){
	View::print();
	std::cout << "*** Print Button ***\nWidth = "<< width << "\nHeight = " << height << std::endl;
}
