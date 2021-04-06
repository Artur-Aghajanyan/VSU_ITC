#include <iostream>
#include <vector>
#include <cstring>

class vector{
	private:
		int size;
		int* massiv;
	public:
		vector(){
			size = 0;
			massiv = nullptr;
		}

		vector(int size){
			size = this->size;
			massiv = new int[size];
		}
		vector(int size, int value){
			size = this->size;
			massiv = new int[size];
			for(int i = 0; i < size; ++i){
			massiv[i] = value;
			}
		}
		void push_back(int value){
			int* temp = new int[size + 1];
			memcpy(temp, massiv, size * 4);
			temp[size] = value;
			delete [] massiv;
			massiv = temp;
			++size;
		}
		void print(){
			for(int i = 0; i < size; ++i){
				std::cout << massiv[i] << std::endl;
			}
		}
		void pop_back(){
			int*temp = new int[size - 1];
			memcpy(temp, massiv, (size - 1) * 4);
			delete [] massiv;
			massiv = temp;
			--size;
		}
		void insert(int index, int value){
			int*temp = new int[size + 1];
			memcpy(temp,massiv,(index * 4));
			temp[index] = value;
			memcpy(&temp[index + 1],&massiv[index],(size - index) * 4);
			delete [] massiv;
			massiv = temp;
			++size;
		}
		bool empty(){
			if(size == 0){
				return true;
			} return false;
		}
		int operator[](int i){
			return massiv[i];
		}
};

int main(){
	vector v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.print();
	//	v.pop_back();
	//	v.print();
	//	v.insert(0,0);
    //	v.print();
	    std::cout << v[2] << std::endl;

}
