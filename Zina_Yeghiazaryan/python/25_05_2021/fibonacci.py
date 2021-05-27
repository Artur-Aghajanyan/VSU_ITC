def Fib(n):
    '''
        Fib function has one argument, which should be a natural number (n).
        The function returns the n-th Fibonacci item.
    '''
    if n < 0:
        print("Entered wrong value. Please enter positive number.")
        return
    else:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n > 1:
            a = 0
            b = 1
            k = -1
            for i in range(n):
                k = a + b
                a = b
                b = k
            return k

while True:
    try:
        n = int(input("Enter the number: "))
        print(str(n) + " Fibonacci item is: " + str(Fib(n - 1)))
    except ValueError:
        print("Entered wrong value. Please enter positive number.")
        print()
