#include <iostream>
#define Inf   999999
#define SIZE  5

void dijskra(int arr[SIZE][SIZE], int key){
	int unvisited[SIZE];
	int visited[SIZE];
	for(int i = 0; i < SIZE; ++i){
		visited[i] = Inf;
		unvisited[i] = arr[key][i];
	}
	visited[key] = key;
	
	
	int index = -1;
	bool visit = true;
	int g = 0;
	while(SIZE > g){
		g++;
		int min = unvisited[0];
		for(int j = 0; j < SIZE; ++j){
			if(unvisited[j] < min && visited[j] == Inf){
				min = unvisited[j];
				index = j;
			}
		}
		visited[index] = index;
		for(int i = 0; i < SIZE; ++i){
			if(unvisited[index] + arr[index][i] < unvisited[i]){
				unvisited[i] = arr[index][i]+unvisited[index];
			}
		}
	}
	for(int k = 0; k < SIZE; ++k){
		std::cout << "Ways - " << unvisited[k]<<"\n";
	}
		
}


int main() {
	int graph[SIZE][SIZE] = {
		{0,2,Inf,Inf,Inf},
		{2,0,1,10,Inf},
		{Inf,1,0,5,4},
		{Inf,10,5,0,Inf},
		{Inf,Inf,4,Inf,0}
	};

	dijskra(graph, 4);
	return 0;
}
