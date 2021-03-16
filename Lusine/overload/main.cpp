#include <iostream>
#include <string.h>
#include "ovrl.h"

int main()
{
    List<std::string> list;
    std::string a = "";
    while (a != "end")
    {
         std::cin >> a;
         list.push(a);
// for integer   list.push(atoi(a.data()));                                     
    }
    list.pop();
    std::cout << std::endl <<"Call pop function" << std::endl;
    list.print();
    list.erase(2);
    std::cout << std::endl <<"Call erase function"<< std::endl;
    list.print();
    std::cout << std::endl <<"Call insert function"<< std::endl;
    list.insert(3, "m"); // for integer list.insert(3, 5);
    list.print();
    std::cout << std::endl <<"Get [i] element" << std::endl;
    list.operator[](6);
    return 0;

}
    
