#include <iostream>
#include "text.h"
#include "button.h"
#include "base.h"

int main()

{
    View objView(5, 6);
    Button objButton(7, 8, 6, 9);
    Text objText(8, 9, "red", "text", "green");

   
    std::cout << std::endl << "objView";
    std::cout << std::endl << objView.x << " " << objView.y << " " << objView.color;
    std::cout << std::endl << "objButton";
    std::cout << std::endl << objButton.x << " " << objButton.y << " " << objButton.width << " " <<  objButton.height;
    std::cout << std::endl << "objText";
    std::cout << std::endl << objText.x << " " << objText.y << " " << objText.color << " " << objText.text << " " << objText.textColor;
    std::cout << std::endl;

}
