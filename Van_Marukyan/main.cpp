#include <iostream>
#include <cstring>
namespace itc{
    class string{
	public:
            char* data;
	    int lenght_text;
	    string(const char* text){
	       lenght_text=strlen(text);
	       data = new char[lenght_text];
	       strcpy(data, text);
	    }
	    friend std :: ostream& operator<<(std :: ostream& os, const string& town);
     };
    std :: ostream& operator<<(std :: ostream& os, const string& town)
    {
        os << town.data;
        return os;
    }
}
int main(){
    itc::string city("Kirovakan");
    std::cout <<city <<std::endl;
    return 0;
}
