int  print_fact(int m)
{
    unsigned long long factorial = 1;
    for (int i = 1; i <= m; ++i) 
    {
        factorial *= i;
    }
    return factorial;
}
