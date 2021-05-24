#include<iostream>
using namespace std;

int ways(int n) {
	if (n == 1)     
		return 4;     

	int buildings = 1;
	int emptySpace = 1;
	int emptySpaceCounter = 0;
	int	buildingsCounter = 0;

    for (int i=2; i<=n; i++) { 
        buildingsCounter = buildings;
		emptySpaceCounter = emptySpace;

        emptySpace = buildings + emptySpaceCounter;
        buildings = emptySpaceCounter;
    }  
    int res = emptySpace + buildings;

    return (res*res); 
}

int main() {
	int number;
	std::cout << "Give me number for buldings: ";
	std::cin >> number;
	std::cout << "Buildings can be constructed in " << ways(number) <<" ways! \n";
}
