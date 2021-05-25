#include <iostream>
#include <string.h>
#include "string.h"


ITC::string::string(const char* text){
    this->size = strlen(text);
    this->data = new char[size];
    strcpy(data,text);

}
namespace ITC{
	std::ostream& operator<<(std::ostream& object, const string& string)
{

	object << string.data;
	return object;
	}
}
