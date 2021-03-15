template <class T>
class Arr {
    private:
        T* data;
        int size;
    public:
        Arr();
        void push(T element);
        void pop();
        void irase(int index);
        void print();
        ~Arr();
};

template <class T>
Arr<T> :: Arr() {
    data = nullptr;
    size = 0;
}

template <class T>
void Arr<T> :: push(T element) {
    T* newdata = new T[size + 1];
    if(data) {
        std :: copy (data, data + size, newdata);
    }
    ++size;
    delete []data;
    data = newdata;
    data[size - 1] = element;
}

template <class T>
void Arr<T> :: pop() {
    if(data) {
        T* newdata = new T[size - 1];
        std :: copy (data, data + size - 1, newdata);
        --size;
        delete []data;
        data = newdata;   
    }
}

template <class T>
void Arr<T> :: irase(int index) {
    if(data) {
        T* newdata = new T[size - 1];
        std :: copy (data, data + index, newdata);
        std :: copy (data + index + 1, data + size , newdata + index);
        --size;
        delete []data;
        data = newdata;
    }
}

template <class T>
void Arr<T> :: print() {
    if(data) {
        for(int i = 0; i < size; ++i) {
            std :: cout << data[i] << "\t";
        }
        std :: cout << std :: endl;
    } else {
        std :: cout << "no data" << std :: endl;
    }
}

template <class T>
Arr<T> :: ~Arr() {
    delete []data;
}