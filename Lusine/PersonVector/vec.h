#include <vector>

class Person
{
    public:
        int age;
        int height;
        Person();
        ~Person();
        Person(int a, int h);
        void Copy(const Person& obj);
};

template <class T>
class myVector : public std::vector<T>
{
    public:
    void sortBy(std::string key);
    void print();
};

Person::Person()
{
    this -> age = 0;
    this -> height = 0;
}

Person::Person(int a, int h)
{
    this -> age = a;
    this -> height = h;
}

Person::~Person(){}

void Person::Copy(const Person &obj)
{
    Person person;
    person.age = obj.age;
    person.height = obj.height;
}

template <class T>
void myVector<T>::sortBy(std::string key)
{
    myVector<Person>::iterator i;
    myVector<Person>::iterator j;
    for(i = this -> begin(); i < this -> end() - 1; ++i)
    {
        for(j = i + 1; j < this -> end(); ++j)
        {
            if(i -> age > j -> age && key == "age")
            {
            std::swap(*i, *j);
            }
        }
    }

    for(i = this -> begin(); i < this -> end() - 1; ++i)
    {
        for(j = i + 1; j < this -> end(); ++j)
        {
            if(i -> height > j -> height && key == "height")
            std::swap(*i, *j);
        }
    }
}

template <class T>
void myVector<T>::print()
{
    myVector<Person>::iterator i;
    for(i = this -> begin(); i < this -> end(); ++i)
    {
        std::cout << "age = " << i -> age << "  :  height = " << i -> height << std::endl;
    }
    std::cout << std::endl;
}
