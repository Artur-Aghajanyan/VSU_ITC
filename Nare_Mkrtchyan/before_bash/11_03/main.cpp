#include <iostream>
#include <memory.h>

class Player{
	public:
	Player(){for(int i=0; i<13; i++)ranks[i]=i;}
	Player(const Player& a){
	this->age=a.age;
	this->ranks = new double[13];
	memcpy(this->ranks, a.ranks, 104);
	}
int age;
	double* ranks = new double[13];

	void setAge(int a){
	this->age=a;
	}
	
};
int main(){

	Player Domi;
	Domi.setAge(27);
	std::cout<<Domi.age<<std::endl;
	
	Player Andy=Domi;
	Andy.setAge(33);
	
	std::cout<<Andy.age<<std::endl;
	
	std::cout<<Domi.ranks[3]<<std::endl;
	std::cout<<Andy.ranks[3]<<std::endl;

	Andy.ranks[3]=10;

	std::cout<<std::endl;
	
	std::cout<<Domi.ranks[3]<<std::endl;
	std::cout<<Andy.ranks[3]<<std::endl;
return 0;
}
