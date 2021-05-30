def Fibonacci(n):
    if n <= 0:
        print("Number cant be less or equal  0")
    elif n==1:
        return 0
    elif n==2:
        return 1
    else:
        return Fibonacci(n-1)+Fibonacci(n-2)

try:
    a = int(input("Enter number "))
    print(Fibonacci(a))
except ValueError:
    print("It is not an integer number!")

