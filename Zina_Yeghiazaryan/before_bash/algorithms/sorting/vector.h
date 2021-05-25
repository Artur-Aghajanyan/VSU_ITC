#include <iostream>
#include <iterator>
#include <cstring>
#include <vector>

template <class T>
class Vector : public std :: vector<T> {
	public:
		void Sort (std :: string key);
		void print (void);
};

template <class T>
void Vector<T> :: Sort (std :: string key) {
	Vector<Person> :: iterator i;
	Vector<Person> :: iterator j;
	
	for (i = this -> begin(); i < this -> end(); ++i) {
		for (j = this -> begin(); j < this -> end() - 1; ++j) {
			if (j -> age > (j + 1) -> age && key == "age") {
				Person k = *j;
				*j = *(j + 1);
				*(j + 1) = k;
			}
			
			if (j -> height > (j + 1) -> height && key == "height") {
				Person k = *j;
				*j = *(j + 1);
				*(j + 1) = k;
			}
		}
	}
}

template <class T>
void Vector<T> :: print(void) {
	Vector<Person> :: iterator l;
	
	for (l = this -> begin(); l < this -> end(); ++l) {
		std :: cout << "Age = " << l -> age << std :: endl << "Height = " << l -> height << std :: endl;
	}
}
