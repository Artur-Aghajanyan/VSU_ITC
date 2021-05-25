#include <iostream>
#include "code.h"

int main()
{
    std::cout << "\nPushing array and print \n";
    array<int> arr;     
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.print();
    std::cout << "\nCall pop function \n";
    arr.pop();
    arr.print();
    std::cout << "\nCall erase function \n";
    arr.erase(0);
    arr.print();
    std::cout << "\nPushing string and print \n";
    array<std::string> str;
    str.push("b");
    str.push("d");
    str.push("f");
    str.push("h");
    str.print();
    std::cout << "\nCall pop function \n";
    str.pop();
    str.print();
    std::cout << "\nCall erase function \n";
    str.erase(1);
    str.print();
    std::cout << std::endl;

    return 0;
}

