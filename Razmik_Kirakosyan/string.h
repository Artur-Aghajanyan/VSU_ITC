template <class T>
class array{
	private:
		T* data;
		int size;
	public:
		void push(T elem);
		void print();
		array();
		~array();
};
template <class T>
array<T> :: array(){
		data=nullptr; size=0;
}
template <class T>
void array<T> :: push(T elem){
		T* newdata = new T[size+1];
			if(data){
				std::copy(data, data + size, newdata);
			}
			++size;
			delete[]data;
			data = newdata;
			data[size - 1] = elem;
}
template <class T>
void array<T>:: print() {
	if(data){
		for(int i=0; i< size; i++){
				std::cout <<data[i] << "   " <<std::endl;
		}
	}
		else {
				std::cout << "data doesn't exsist" <<std::endl;
		}
}
template <class T>
array<T>:: ~array() {
delete[] data;
}
