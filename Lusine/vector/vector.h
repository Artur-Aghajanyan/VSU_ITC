class Vector 
{
private:
    unsigned size;
    unsigned capacity;
    int* vec;
public:    
    Vector();
    Vector(int size);
    Vector(int size, int value);
    ~Vector();
    void push_back(int element);
    void insert(int index, int value);
    int vectorSize();
    bool empty();
    void pop_back();
    void erase(int index);
    
};

