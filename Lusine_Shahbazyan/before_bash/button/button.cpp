#include "button.h"

Button::Button() : View()
{
    width = 0;
    height = 0;
}

Button::Button(int w, int h) : View()
{
    width = w;
    height = h;
}

Button::Button(int x, int y, int w1, int h1) : View(x, y)
{
    width = w1;
    height = h1;
}

int Button::getWidth() { return width;}
int Button::getHeight() { return height;}
void Button::setWidth(int width) { this-> width = width;}
void Button::setHeight(int height) { this-> height = height;}
