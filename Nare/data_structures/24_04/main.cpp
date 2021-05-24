#include "func.h"

int main() {
    std::cout << "5+2*3-2" << std::endl;
    revPolNot("5+2*3-2", 7); 
    std::cout << "(4+7)+12/3" << std::endl;
    revPolNot("(4+7)+12/3", 10);
    std::cout << "6*3-(4-5)+2" << std::endl;
    revPolNot("6*3-(4-5)+2", 11);
    return 0;
}

