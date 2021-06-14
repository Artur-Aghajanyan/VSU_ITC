def Fibonacci(n):
    if n < 0:
        return("Incorrect input")
    elif n == 0:
        return(1)
    elif n == 1:
        return(1)
    elif n ==2:
        return(1)
    else:
        return(Fibonacci(n - 1) + Fibonacci(n - 2))

print(Fibonacci(7))
