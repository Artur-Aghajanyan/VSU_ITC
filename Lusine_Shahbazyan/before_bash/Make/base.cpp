#include <iostream>
#include "base.h"

View::View()
{
    x = 0; 
    y = 0;
}

View::View(int x1, int y1)
{
    x = x1;
    y = y1;
}

int View::getX() { return x;}
int View::getY() { return y;}
std::string View::getColor() { return color;}
void View::setX(int x) { this->x = x;}
void View::setY(int y) { this->y = y;}
void View::setColor(std::string color) { this->color = color;}
