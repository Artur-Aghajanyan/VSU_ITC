#include "view.h"
#include <iostream>

View :: View() {
    x = 0;
    y = 0;
    color = "blue";
}

View :: View(int x, int y, std :: string color) {
    this -> x = x;
    this -> y = y;
    this -> color = color;
}

int View ::get_x() {
    return x;
}

void View :: set_x(int tmp) {
    this -> x = tmp;
}
        
int View :: get_y() {
    return y;
}
        
void View :: set_y(int tmp) {
    y = tmp;
}
        
std :: string View :: get_color() {
    return color;
}
        
void View :: set_color(std :: string tmp) {
    color = tmp;
}

void View :: print() {
        std :: cout << get_x() << std :: endl;
    std :: cout << get_y() << std :: endl;
    std :: cout << get_color() << std :: endl;
}