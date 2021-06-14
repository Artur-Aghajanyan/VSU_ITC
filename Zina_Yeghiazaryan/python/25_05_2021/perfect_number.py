def divSum(n):
    '''
        DivSum function has one argument, which should be a natural number.
        The function counts the sum of divisors of argument.
    '''
    sum = 0
    for i in range(1, n // 2 + 1):
        if (n % i) == 0:
            sum += i
    return sum

def check(n):
    '''
        Check function has one argument, which should be a natural number.
        The function checks if the argumen is perfect.
    '''
    if n > 0 and (divSum(n) - n) == 0:
        print(str(n) + " is a perfect number.")
    else:
        print(str(n) + " is not a perfect number.")

while True:
    try:
        n = int(input("Enter the number: "))
        if n < 0:
            print("Entered number can't be perfect. Please enter positive number.")
            n
        else:
            check(n)
    except ValueError:
        print("Entered wrong value. Please enter a positive number.")
        print()
