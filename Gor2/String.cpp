#include <iostream>
#include "String.h"
#include <cstring>

namespace ITC{
String::String(const char* text)
{
	size = strlen(text);
	data = new char[size];
	strcpy(data,text);
	data[size] = '\0';
}

char* String::get_data()
{
	return data;
}

std::ostream& operator<< (std::ostream& os, const String& str)
{
	os<<str.data;
	return os;
}

void String::print()
{
	std::cout<<data<<std::endl;
}
}
