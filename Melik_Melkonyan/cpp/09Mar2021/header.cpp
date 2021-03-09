int factorial(int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int fib(int x) {
   if((x == 1) || (x == 0)) {
      return x;
   }else {
      return fib(x - 1) + fib(x - 2);
   }
}

float arithmetic_mean(int size, int arr[]) {
    int sum = 0;
    for(int i = 0; i < size; ++i) {
        sum = sum + arr[i];
    }
    return float(sum) / float(size);
}