#include <iostream>
#include "vector.h"
#include "list.h"
#include "stack.h"

int main() {
  Vector<int> v(5, 10);
  List<int> l;
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(6);

  Stack<int,List<int>> s1(l);
  s1.push(18);
  std::cout <<"List stack" << std::endl;
  while(!s1.empty()) {
      std::cout << s1.top() <<std::endl;
      s1.pop();
  }

  Stack<int,Vector<int>> s2(v);
  s2.push(15);

  std::cout << "Vector stack" << std::endl;
  while(!s2.empty()) {
      std::cout << s2.top() <<std::endl;
      s2.pop();
  }

    std::cout << "Without container type(default type is Vector)" << std::endl;
    Stack<int> s3;
   s3.push(3);
   s3.push(5);
   while(!s3.empty()) {
       std::cout << s3.top() <<std::endl; 
       s3.pop();
   }
    return 0;
}
