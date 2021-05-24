#include "itc_string.h"
#include <iostream>
#include <string.h>
namespace itc{
    //itc::string::string(const char* text){
    string::string(const char* text){
         size = strlen(text);
        data = new char [size];
        strcpy(data,text);
     }
    std::ostream& operator<<(std::ostream& ostr, const string& object)
    {return ostr << object.data;}
    
    //void itc::string::print(){
    void string::print(){
         std::cout<<data<<std::endl;
    }
}
