#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


class My_vector {
	private:
		int size;
		int* massiv;
	public:
		My_vector () {
			size = 0;
			massiv = nullptr;
		}
		My_vector (int chap) {
       		size = chap;
			massiv = new int[size];
        }
	    My_vector (int size1, int value) {
			size = size1;
			massiv = new int[size];
			for(int i = 0; i < size; ++i){
				massiv[i] = value; 
			}
		}
		void push_back(int value) {
			int* temp = new int[size + 1];
			memcpy(temp,massiv,size * 4);
		    temp[size] = value;
			delete [] massiv;
            massiv = temp;
			++size;
		}
		void print () {
			for (int j = 0; j < size; ++j) {
				cout << massiv[j] << endl;
			}
		}
		void pop_back() {
			int* temp1 = new int[size - 1];
			memcpy(temp1, massiv,(size - 1)* 4 );
			delete [] massiv;
			massiv = temp1;
			--size;
		}
        bool empty() {
           if (size == 0 ) {
        		return  true;
           } else {
				return false;
	       }
		}
		
		void insert (int index, int value) {
			int* temp2 = new int[size + 1];
			memcpy(temp2,massiv,index*4);
			temp2[index] = value;
			memcpy(&temp2[index + 1],&massiv[index], (size - index) * 4);
            delete [] massiv;
			massiv = temp2; 
			++size;
		}

        int operator[](int i) { 
			return massiv[i]; 
		}
};		
      
int main () {
	My_vector v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(55);
	v.push_back(77);
	My_vector vec(3, 3);
	v.print();
	v.pop_back();
	v.print();
	vec.print();
	vec.insert(1,3);
    v.insert(3,88);
	v.print();
	cout << endl;
	cout << v[1] << endl;
	return 0;
}
