#include <iostream>
#include <limits.h>
#define size 7
#define myVertex 4
 
int minDistance(int* distance, bool* shortPath)
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < size; ++i)
    {
        if (distance[i] < min && shortPath[i] == false)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
  
void dijkstra(int graph[size][size])
{
    int distance[size]; 
    bool shortPath[size]; 
    for (int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        shortPath[i] = false;
    }
    distance[myVertex] = 0;
    for (int j = 0; j < size; ++j) 
    {
        int index = minDistance(distance, shortPath);
        shortPath[index] = true;
        for (int i = 0; i < size; ++i)
        {
            if(graph[index][i] != 0 && shortPath[i] == false)
            {
                if(distance[index] + graph[index][i] < distance[i])
                {
                    distance[i] = distance[index] + graph[index][i];
                }
            }
        }
    }
    std::cout << "The shortest ways are : \n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << myVertex << " -> " << i << " is  " << distance[i] << std::endl;;
    }
}
  
int main(){
    int graph[size][size] = {
                        { 0, 2, 0, 0, 0, 0, 0 },
                        { 3, 0, 7, 0, 0, 2, 2 },
                        { 0, 8, 0, 7, 0, 0, 0 },
                        { 0, 0, 0, 0, 9, 5, 1 },
                        { 0, 0, 6, 9, 0, 1, 0 },
                        { 0, 0, 9, 3, 2, 0, 2 },
                        { 0, 5, 0, 0, 0, 2, 0 },
    };
    dijkstra(graph);
    return 0;
}




