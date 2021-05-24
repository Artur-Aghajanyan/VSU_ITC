class Person
{
	public:
		int age;
		int height;

		Person();
		Person(int a);
		Person(int a, int h);
		~Person();
		void operator=(const Person& p);
};
