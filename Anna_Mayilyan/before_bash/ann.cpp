#include "string.h"
#include <cstring>
itc::string::string(const char* text)
{
size=strlen(text);
data = new char[size];
strcpy (data,text);
}

