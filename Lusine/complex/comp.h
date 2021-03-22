template <class T>
class Complex {
    private:
        T real;
        T image;
    public:
        /* Default constructor */
        Complex();

        /* Parametrize constructor */
        Complex(T a, T b);

        /* Copy constructor */
        Complex(const Complex<T> &obj);

        /* Getter */      
        T getReal();
        T getImage();

        /* Setter */
        void setReal(T a);
        void setImage(T b);
        
        /* Overloaded operators */
        Complex<T> operator + (const Complex<T> &obj);
        Complex<T> operator - (const Complex<T> &obj);
        Complex<T> operator * (const Complex<T> &obj);

        /* Friend Functions */
        template <class F> 
	friend std::ostream& operator << (std::ostream& cout, const  Complex<F>& obj);
	template <class F> 
	friend std::istream& operator >> (std::istream& cin, Complex<F>& obj); 
};

