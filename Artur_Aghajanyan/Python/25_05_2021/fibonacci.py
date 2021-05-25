fib = input("Give me number for fibonacci: ")


if not fib.isdigit():
    print("Input is string or small than 0")
else:
    fib = int(fib)
    def fibonacci(n):
        a = 1
        b = 1
        if n < 0:
            print("Incorrect input")
        elif n == 0:
            return a
        elif n == 1:
            return b
        else:
            for i in range(2,n):
                c = a + b
                a = b
                b = c
            return b
  
    print(fibonacci(fib))
