#include <iostream>
#include "text.h"

Text :: Text() : View() {
    text = "blue";
    text_color = "black";
}

Text :: Text(int x, int y, std :: string color, std :: string t, std :: string t_c) : View(x,y,color) {
    text = t;
    text_color = t_c;
}

std :: string Text :: get_text() {
    return text;
}
void Text :: set_text(std :: string tmp) {
    text = tmp;
}
std :: string Text :: get_text_color() {
    return text_color;
}
void Text :: set_text_color(std :: string tmp) {
    text_color = tmp;
}

void Text :: print() {
    View :: print();
    std :: cout << get_text() << std :: endl;
    std :: cout << get_text_color() << std :: endl;
}