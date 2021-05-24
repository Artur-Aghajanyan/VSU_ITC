namespace ITC
{
	class String
	{
		char* data;
		int size;
		public:
			String(const char* text);
			char* get_data();
			friend std::ostream& operator<< (std::ostream& os, const String& str);
			void print();
	};
}
