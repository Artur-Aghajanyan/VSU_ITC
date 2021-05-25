#include <iostream>
namespace itc
{
    class string
    {
        public:
    string(const char* text);
friend std::ostream& operator<< (std::ostream&, const string&);
        private:
    int size;
    char* data;
        
    public:
    void print();
    };

}
