#include <iostream>
#include <string.h>
using namespace std;
class Student
{
    public:
    std::string name;
    int* rating;
    Student()
    {
        this-> rating = new int[3];
    }
};

int main()
{
    Student firstStudent;
    std::string n;
    int r;
    cout << "Enter name: "; cin >> n;
    firstStudent.name = n;
    cout << "Enter ratings: "; 
    for(int i = 0; i < 3; i++)
    {
        cin >> r;
        firstStudent.rating[i] = r;
    }
    Student secondStudent;
    memcpy (secondStudent.rating, firstStudent.rating,12); 
    cout << firstStudent.name << "\n";
    for(int i = 0; i < 3; i++)
    {
        cout << secondStudent.rating[i];
    }
    cout << "\n";
    for(int i = 0; i < 3; i++)
    {
        firstStudent.rating[i] = 5;
    }
    for(int i = 0; i < 3; i++)
    {
        cout << firstStudent.rating[i];
    }
    cout << "\n";
    for(int i = 0; i < 3; i++)
    {
        cout << secondStudent.rating[i];
    }
    
    delete[] firstStudent.rating;
    delete[] secondStudent.rating;
}
