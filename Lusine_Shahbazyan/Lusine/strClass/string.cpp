#include <iostream> 
#include <stdio.h>
#include <cstring>
#include "string.h"

itc::String::String(const char* n)
{
    size = strlen(n);
    data = new char[size];
    strcpy(data, n);
}

void itc::String::print()
{
    std::cout << data << "\n";
}
