#include <iostream>
#include "button.h"
#include "view.h"


Button::Button(){
	width = 0;
	height = 0;
}


Button::Button(int w,int h){
		width = w;
		height = h;
	   }


Button::Button(int x,int y,int w,int h):View(x,y){
		width = w;
		height = h;
}




int Button::getY(){
    return this->y;
}


int Button::getX(){
	return this->x;
}

int Button::getW(){
	return this->width;
}

int Button::getH(){
	return this->height;
}




void Button::setY(int y){
    this->y = y;	
}


void Button::setX(int x){
	this->x = x;
}

void Button::setW(int w){
	this->width = w;
}

void Button::setH(int h){
	this->height = h;
}


