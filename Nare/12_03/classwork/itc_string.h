namespace itc
{
    class string
    {
        public:
    string(const char* text);

        private:
    int size;
    char* data;
        
    public:
    void print();
    };
}
