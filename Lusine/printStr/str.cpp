#include <iostream>
#include <cstring>

#include "str.h"

namespace itc
{
    String::String(const char* n)
    {
        size = strlen(n);
	data = new char[size];
	strcpy(data, n);
    }

    std::ostream& operator << (std::ostream& x, const String& myObj)
    {
        return x << myObj.data;
    }
}
