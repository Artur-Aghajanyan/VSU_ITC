#include <iostream>
using namespace std;


void merge(int *array,int l,int m,int r) {
	int n1 = m - l + 1;
	int n2 = r-m;

	int L[n1],M[n2];

	for(int i = 0;i < n1; ++i) {
		L[i] = array[l+i];
	}
	for(int i = 0;i < n2; ++i) {
		M[i] = array[m + 1 + i];
	}

	int i,j,k;
	i = 0;
	j = 0;
	k = l;

 while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int *array,int l,int r) {
	if (l < r) {
	int m = l+(r-l)/2;
	mergeSort(array,l,m);
	mergeSort(array,m+1,r);
	merge(array,l,m,r);
	}		
}

void printArray(int *array) {
	for (int i = 0;i < 10;++i) {
	cout<<array[i]<<" ";
	cout<<endl;	
	}
}


int main() {
	int size = 10;
	int array[size] = {14,45,78,1,98,12,25,10,85,100};
	printArray(array);
	cout<<"-----------Merge sort-----------"<<endl;	
	mergeSort(array,0,9);
	printArray(array);
	
		
		
	return 0;
}
