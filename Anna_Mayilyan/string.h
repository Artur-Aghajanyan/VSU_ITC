#include <iostream>
namespace itc{
class string{
public:
string(const char* text);
private:
char* data;
int size;
friend std::ostream& operator<< ( std::ostream &out, const itc::string &p)
{
        for(int i=0; i < p.size; i++)
	{
                out << p.data[i];
        }
return out;
}
};
}

