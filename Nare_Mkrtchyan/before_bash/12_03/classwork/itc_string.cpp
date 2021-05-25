#include "itc_string.h"
#include <iostream>
#include <string.h>

 itc::string::string(const char* text){
 size = strlen(text);
 data = new char [size];
 strcpy(data,text);
 }

void itc::string::print(){
     std::cout<<data<<std::endl;
 }
