#ifndef COMPLEX
#define COMPLEX

template <class T> class Complex;
template <class A> std::ostream& operator<<(std::ostream& comp, const Complex<A>& a);
template <class A> std::istream& operator>>(std::istream& comp, Complex<A>& a);

template <class T>
class Complex {
    private:
        T real;
        T image;

    public:
        /*
         Constructors
        */ 
        Complex();
        Complex(T, T);
        Complex(const Complex<T>& a);

        /*
         Setters and getters
        */ 
        void setReal(T r);  
        void setImage(T im);

        T getReal();
        T getImage();
        
        /*
         Overloaded +,-,*,/ operators
        */ 
        Complex<T> operator+(const Complex& a);
        Complex<T> operator-(const Complex& a);
        Complex<T> operator*(const Complex& a);
        Complex<T> operator/(const Complex& a);

        /*
         Overload <<, >> operators
        */
       template <class A> 
        friend std::ostream& operator<<(std::ostream& comp, const Complex<A>& a);
       template <class A>
        friend std::istream& operator>>(std::istream& comp, Complex<A>& a);
        
};

/*
 Overload Output operator<<
*/
template <class T>
std::ostream& operator<<(std::ostream& comp, const Complex<T>& a) {
    if(a.real != 0) {
        if(a.image != 0 ) {
            if(a.image > 0) {
                return comp << a.real << "+" << a.image << "i";
            }
            else {
                return comp << a.real << "" << a.image << "i";
            }
        }
        else {
            return comp << a.real;
        }
    }
    else if(a.image == 0) {
        return comp << 0;
    }
        return comp << a.image << "i";

}
/*
 Overload Input operator>>
*/
template <class T>
std::istream& operator>>(std::istream& comp, Complex<T>& a) {
    return comp >> a.real >> a.image;
}

#endif
