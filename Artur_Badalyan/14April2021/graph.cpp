#include <iostream>
using namespace std;
#define size 5
#define inf 2000000

int dijikstra(int *array,int num) {
	int vis[size];
	int unvis[size];

	for(int i = 0;i < size;++i) {
		vis[i] = inf;
		unvis[i] = array[num][i];
	}
	int index = -1;
	int min = unvis[0];
	int j = 0;
while (size > j) {	
	for (int i = 1;i < size;++i) {
		if (min < unvis[i] && vis[i] == inf) {
			min = unvis[i];
			index = i;
			vis[index] = i;
		}
	}

	++j;
}	


int main(){
	
	int array[size][size] = {{0,2,inf,inf,inf},
				    		{2,0,1,10,inf},
				    		{inf,1,0,5,4},
				    		{inf,10,5,0,inf},
				    		{inf,inf,4,inf,0}};
	

	return 0;
}
