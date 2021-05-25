#include <iostream>
#include "templ.h"
#include <typeinfo>
int main(){

   array<int> a;
array<std::string> b;
std::cout<<"Enter numbers:"<<std::endl;
    while(true){
        std::string s;
        std::cin>>s;
        if(s=="end"){
            break;
        }
        else {
           int x=atoi(s.data());
           a.push(x);
        }
    }
        
std::cout<<"Enter string:"<<std::endl;
    while(true){
        std::string c;
        std::cin>>c;
        if(c=="end"){
            break;
        }
        else{
          b.push(c);
        }
    }
    a.get();
    b.get();
    std::cout<<"Popped arrays:"<<std::endl;
    a.pop();
    a.get();
    b.pop();
    b.get();
    std::cout<<"Erased arrays:"<<std::endl;
   a.erase(2);
   a.get();
    b.erase(1);
    b.get();
  return 0;
}
