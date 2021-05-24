#include <iostream>
using namespace std;

int quick(int *array,int start,int end)
{
	int p = array[end];
	int in = start;
  
    for(int i=start; i<end; i++)
    {
    	if(array[i] <= p)
        {
            int temp = array[i];
            array[i]=array[in];
            array[in]=temp;
            in++;
        }
     }

     int temp = array[end];
     array[end] = array[in];
     array[in] = temp;
    
     return in;
 }
 void quickSort(int *array,int start,int end)
 {
    if(start<end)
    {
         int in = quick(array,start,end);
             quickSort(array,start,in-1);
             quickSort(array,in+1,end);
    }
}

void printArray(int *array,int size){
	for(int i = 0;i < size;++i) {
		cout<<array[i]<<" ";
	}
}

int main() {
	int size = 8;	
	int array[] = {5,25,63,7,6,10,12,8};
	printArray(array,size);
	quickSort(array,0,size-1);
	cout<<"\n-------Quick sort--------------"<<endl;	
	printArray(array,size);
	return 0;
}
