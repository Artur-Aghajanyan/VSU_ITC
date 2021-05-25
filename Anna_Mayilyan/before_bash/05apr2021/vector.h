class Array
{
private:
    int *data;
    int size;
public:
    Array();
    Array(const Array& v);
    Array(int n);
    void push(int  a);
    void get();
	void insert(int index, int value);
	int Size();
	bool empty();
	int& operator[] (int);
	void pop_back();
    ~Array();
};

