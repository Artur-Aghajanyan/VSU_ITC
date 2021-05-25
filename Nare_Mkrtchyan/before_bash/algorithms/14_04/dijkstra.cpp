#include <iostream>

void dijskra(int **arr, int n);
int main() {

    int size;
    std::cout << "Enter size" << std::endl;
    std::cin >> size;

    int **array;
    array = new int *[size];
    for(int i = 0; i <size; i++)
        array[i] = new int[size];

    std::cout << "Enter matrix elements" << std::endl;
    for(int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "arr[ " << i << " ][ " << j << " ] = ";
            std::cin >> array[i][j];
        }
    }

    dijskra(array, size);
    return 0;
}

void dijskra(int **arr, int n) {
    bool sptSet[n];
    int dist[n];

    
    dist[0] = 0;
    for (int i = 1; i < n; ++i) {
        dist[i] = 100000;
        sptSet[i] = false;
    }
    sptSet[0] = true;
    int i = 0;

    for(int j = 0; j < n; ++j) {
        if(arr[i][j] != 0 ) {
            dist[j] = arr[i][j];
        }
    }

bool end = false;

while(!end) {
    end = true;
    int min = 100000;
    int index = -1;

    for(int j = 0; j < n; ++j) {
        if(dist[j] < min && sptSet[j] == false) {
            min = dist[j];
            index = j;
        }
    }
    
    sptSet[index] = true;
    
   for(int j = 0; j < n; ++j) {
        if(arr[index][j] != 0 && sptSet[j] == false) {
            if(dist[index] + arr[index][j] < dist[j]){
                dist[j] = dist[index] + arr[index][j];
            }
        }
   }
    for(int k = 0; k < n; ++k) {
        if(!sptSet[k]) {
            end = false;
            break;
        }
    }

}

for(int k = 0; k < n; ++k) {
    std::cout << k <<": " << dist[k] << std::endl;
}

}
