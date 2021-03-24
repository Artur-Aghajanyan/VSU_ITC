#include <iostream>
#include "button.h"
#include "text.h"


int main() {
    Button obj;
    obj.set_x(10);
    obj.set_y(15);
    obj.set_color("black");
    obj.set_height(100);
    obj.set_width(200);
    std :: cout << std :: endl;
    obj.print();
    Text but;
    but.set_x(10);
    but.set_y(15);
    but.set_color("black");
    but.set_text("hello");
    but.set_text_color("yelow");
    std :: cout << std :: endl;
    but.print();
}