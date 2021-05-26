class Vector {
    private:
        int* vector;
        int size;

    public:
        Vector();
        Vector(int s);
        Vector(int s, int val);
        Vector(const Vector &v);

        int Size();
        int capacity();
        void popBack();
        void pushBack(const int& val);
        void insert(int index, int val);
        void print();
        bool empty();
        int &operator[](int i);
};
