#include "string.h"
#include <string.h>
#include <iostream>

my :: string :: string(const char* text) {
    this -> size = strlen(text);
    this -> data = new char[size];
    strcpy(this -> data, text);
}

char* my :: string :: get_data() {
    return this -> data;
} 
namespace my {
std :: ostream& operator<<(std :: ostream& os, const string& object) {
    return os << object.data;
}
}