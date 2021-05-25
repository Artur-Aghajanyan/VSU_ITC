#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> stack;
    std::cout << "Stack is empty  : ";
    std::cout << stack.empty() << std::endl;
    std::cout << "Stack size is : ";
    std::cout<<stack.getSize() << std::endl;
  
    Stack <int> stack1();
    Stack <int> stack2(5);
    stack2.push(6);
    stack2.push(8);
    stack2.push(3);
    stack2.push(1);
    std::cout << "After pushing elements " << std::endl;
    std::cout << "Stack is empty  : ";
    std::cout << stack.empty() << std::endl;
    std::cout << "Stack size is : ";
    std::cout << stack2.getSize() << std::endl;
    std::cout << "Top of stack is  : ";
    std::cout<< stack2.top()<< std::endl;
    stack2.pop();
    std::cout << "After poping the top of stack is  : ";
    std::cout<< stack2.top()<< std::endl;
      
}
