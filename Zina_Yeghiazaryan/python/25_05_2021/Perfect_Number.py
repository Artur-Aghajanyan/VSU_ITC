def DivSum(n):
    sum = 0
    for i in range(1, n // 2 + 1):
        if (n % i) == 0:
            sum += i
    return sum

def Check(n):
    if (DivSum(n) - n) == 0:
        print(str(n) + " is a perfect number.")
    else:
        print(str(n) + " is not a perfect number.")

while True:
    try:
        n = int(input("Enter the number: "))
        Check(n)
    except ValueError:
        print("Entered wrong value. Please enter a number.")
        print()
