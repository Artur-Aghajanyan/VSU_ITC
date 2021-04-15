#include <iostream>
#include <climits>

using namespace std;

void print(int* arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<""<<endl;
}

void bellman(int graph[][3],int top_count,int edge_count,int top)
{
	int dist[top_count];
	for(int i = 0; i < top_count; i++)
	{
		dist [i] = 1000;
	}
	dist[top] = 0;
	for(int i = 0; i < top_count - 1; i++)
	{
		for(int j = 0; j < edge_count; j++)
		{
			if(dist[graph[j][0]] + graph[j][2]<dist[graph[j][1]])
			{
				dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];

			}
		}
	}
	print(dist,top_count);
}

int main()
{
	int top_count = 5;
	int edge_count = 5;
	int graph [][3] = {{0,1,1} ,
			   {0,2,5} ,
			   {1,3,-5},
			   {2,1,-6},
			   {3,4,3}
			  };
	bellman(graph,top_count,edge_count,0);
	return 0;
}
