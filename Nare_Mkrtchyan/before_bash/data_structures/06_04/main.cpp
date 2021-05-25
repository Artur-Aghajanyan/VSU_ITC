#include <iostream>
#include "stack.h"

bool bracket(std::string str);

int main() {
    Stack<int> s1;
    Stack<int> s2;
    for(int i = 0; i < 5; ++i) {
        s1.push(16);
    }
    for(int i = 0; i < 3; ++i) {  
        s2.push(20);
    }  
   // s.top() -= 5;
   s1.swap(s2);
   s1.push(55);
    std::cout << "s's size is: " << s1.Size() << std::endl;
    std::cout << "s's size is: " << s2.Size() << std::endl;
    while(!s1.empty()) {
        std::cout << s1.top() << std::endl;
        s1.pop();
    } 
    while(!s2.empty()) {
        std::cout << s2.top() << std::endl;
        s2.pop();
    }

//string
    std::string string = "([])asd";
   if(bracket(string)) {
    std::cout << "true" << std::endl;
   } 
   else {
   
    std::cout << "false" << std::endl;
   }
    return 0;
}
