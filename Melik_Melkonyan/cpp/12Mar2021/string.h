#include <iostream>

namespace my {
    class string {
        private:
            int size;
            char* data;
        public:
        
            string(const char*);
            char* get_data();
            friend std :: ostream& operator<<(std :: ostream& os, const string& object);
    };
}