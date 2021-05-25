#include <string>
#include <iostream>
#include "view.h"

View :: View() {
	x = 0;
	y = 0;
	color = "";
}

View :: View(int x, int y, std :: string color) {
	this -> x = x;
	this -> y = y;
	this -> color = color;

}

void View :: setX(int x1) {
	x = x1;
}

void View :: setY(int y1) {
	y = y1;
}

void View :: setColor(std :: string c) {
	color = c;
}

int View :: getX() {
	return x;
}

int View :: getY() {
        return y;
}

std :: string View :: getColor() {
	return color;
}

void View :: print() {
	std :: cout << x << ' ' << y << ' ' << color << ' ';
}
