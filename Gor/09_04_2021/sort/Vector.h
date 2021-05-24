#include <iostream>
#include <vector>
#include <iterator>
#include "Person.h"

using namespace std;

template <class T>
class myVector:public vector<T>
{
	public:
		void Sort(string s)
		{
			myVector<Person>::iterator ptr_1;
			myVector<Person>::iterator ptr_2;
			for(ptr_1 = this->begin(); ptr_1 < this->end(); ptr_1++)
			{
				for(ptr_2 = this->begin(); ptr_2 < this->end(); ptr_2++)
				{
					if(ptr_2->age > (ptr_2+1)->age && s == "age")
					{
						Person p;
						p = *ptr_2;
						*ptr_2 = *(ptr_2+1);
						*(ptr_2+1) = p;
					}
					
					if(ptr_2->height > (ptr_2+1)->height && s == "height")
                                        {
                                                Person p;
                                                p = *ptr_2;
                                                *ptr_2 = *(ptr_2+1);
                                                *(ptr_2+1) = p;
                                        }
				}
			}		
		}

		void print()
		{
			myVector<Person>::iterator ptr;
			for(ptr = this->begin(); ptr < this->end(); ptr++)
			{
				cout<<"age = "<<ptr->age<<" "<<"\theight = "<<ptr->height<<endl;
			}	
		}
};
