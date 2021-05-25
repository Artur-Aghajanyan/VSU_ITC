#include <iostream>
#include <string>
#include "view.h"
#include "button.h"
#include "text.h"


int main() {
    Button b(1, 2, "b", 3, 4);
    b.print();
    Button b1;
    b1.setX(1);
    b1.setY(2);
    b1.setColor("blue");
    b1.setHeight(10);
    b1.setWidth(10);
    std :: cout << std :: endl;
    b1.print();
    Text t;
    t.setX(1);
    t.setY(2);
    t.setColor("red");
    t.setText("DANGER");
    t.setTc("black");
    std :: cout << std :: endl;
    t.print();
}
