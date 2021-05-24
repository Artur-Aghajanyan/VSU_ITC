#include <iostream>
#include <cstring>
#include "string.h"

ITC::String::String(const char* text){
		this->size = strlen(text);
		this->data = new char[this->size];
		strcpy(this->data, text);
		this->data[size] = '\0';
}

ITC::String::~String(){
	delete[] this->data;
	std::cout << "deleted\n";
}

namespace ITC{
	std::ostream& operator<<(std::ostream& os, const ITC::String& string ){
			return os<< string.data;
	}
}
