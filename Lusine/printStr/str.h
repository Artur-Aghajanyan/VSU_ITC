namespace itc
{
    class String
    {
        public:
	    String(const char* t);
	    friend std::ostream& operator << (std::ostream&, const String&);
	private:
	    char* data;
	    int size;
    };
}
