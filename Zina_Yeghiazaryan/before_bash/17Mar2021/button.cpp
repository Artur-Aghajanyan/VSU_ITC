#include <iostream>
#include "button.h"

Button :: Button() : View() {
    width = 0;
    height = 0;
}

Button :: Button(int w, int h) : View() {
    width = w;
    height = h;
}

Button :: Button(int x, int y, int w, int h, std :: string c) : View(x,y,c) {
    width = w;
    height = h;
}

int Button :: get_width() {
    return width;
}
        
void Button :: set_width(int tmp) {
    width = tmp;
}
        
int Button :: get_height() {
    return height;
}
        
void Button :: set_height(int tmp) {
    height = tmp;
}

void Button :: print() {
    View :: print();
    std :: cout << get_width() << std :: endl;
    std :: cout << get_height() << std :: endl;
}