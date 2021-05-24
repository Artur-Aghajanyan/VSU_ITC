double print_average( int* arr, int m)
{ 
    double sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum += arr[i];
    }
    sum = sum / m;
    return sum;
}
