#include <iostream>
#include <cstring>
#include "String.h"
#include <ostream>

itc :: String :: String (const char* text) {
	size = strlen(text);
	data = new char [size];
	strcpy (data, text);
	data[size] = '\0';
}

std :: ostream& operator << (std :: ostream& out, const itc :: String& text) {
	out << text.data;
	return out;
}

itc :: String :: ~String () {
	delete [] data;
}
