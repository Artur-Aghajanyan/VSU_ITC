class Complex {
    private:
        int real;
        int image;

    public:
        /*
         Constructors
        */ 
        Complex();
        Complex(int, int);
        Complex(const Complex& a);

        /*
         Overloaded +,-,*,/ operators
        */ 
        Complex operator+(const Complex& a);
        Complex operator-(const Complex& a);
        Complex operator*(const Complex& a);
        Complex operator/(const Complex& a);

        /*
         Overload <<, >> operators
        */ 
        friend std::ostream& operator<<(std::ostream& comp, const Complex& a);
        friend std::istream& operator>>(std::istream& comp, Complex& a);

        /*
         function with static member
        */ 
};
