#include <iostream>
#include <string.h>
#include "doubleList.h"

int main()
{
    List<std::string> list;
    std::string a = "";
    while (a != "end") 
    {
	 std::cin >> a;
	 list.push(a);  // for integer   list.push(atoi(a.data()));
    }
    list.print();
    list.pop();
    std::cout << std::endl <<"Call pop function" << std::endl;
    list.print();
    list.erase(2);
    std::cout << std::endl <<"Call erase function for 2 index"<< std::endl;
    list.print();
    std::cout << std::endl << "Insert 'm' in position 3"<< std::endl;
    list.insert(3, "m"); // for integer list.insert(3, 5);
    list.print();
    return 0;
}
