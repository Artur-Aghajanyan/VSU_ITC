def Fib(n):
    '''
        Fib function has one argument, which should be a natural number (n).
        The function returns the n-th Fibonacci item.
    '''
    if n == 0:
        return 0
    if n == 1:
        return 1
    return Fib(n - 1) + Fib(n - 2)

while True:
    try:
        n = int(input("Enter the number: "))
        print(str(n) + " Fibonacci item is: " + str(Fib(n - 1)))
    except ValueError:
        print("Entered wrong value. Please enter a number.")
        print()
