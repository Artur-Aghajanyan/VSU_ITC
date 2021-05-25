class Complex
{
    private:
        int real;
        int image;

    public:
        static   int count;//static variable of class
        Complex();//definition of default constructor
        Complex(int r, int i);//definition ob parametrized constructor
        Complex(const Complex  &c);//definition of copy constructor
        //definition of input and output functions for overloading
        friend std::ostream& operator<< (std::ostream& out, const Complex& c);
        friend std::istream& operator>> (std::istream &in,  Complex &c);
        //definition of functions for overloading arithmetic operations
        friend Complex operator+ ( Complex const &, Complex const &);
        friend Complex operator- (Complex const &a,  Complex const &b);
        friend Complex operator* (Complex const &c1, Complex const &c2);
};

