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
	    friend std :: ostream& operator<<(std :: ostream& os, const string& village);
     };



    std :: ostream& operator<<(std :: ostream& os, const string& village)
    {
        os << village.data;
        return os;
    }
}
int main(){
    itc::string village("Vahagni");
    std::cout <<village  <<std::endl;
    return 0;
}
