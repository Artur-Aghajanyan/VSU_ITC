def Fact(n):
    '''
        Fact function has one argument, which should be a natural number.
        The function counts given number's factorial.
    '''
    if n == 0 or n == 1:
        return 1
    if n > 1:
        return Fact(n - 1) * n

def Pascal(n):
    '''
        Pascal function has one argument, which should be a natural number (n).
        The function prints out the first n rows of Pascal's triangle.
    '''
    for i in range(0, n+1):
        for j in range(0, i+1):
            k = Fact(i)/(Fact(j) * Fact(i-j))
            print(k, end = ' ')
        print("\n")

while True:
    try:
        n = int(input("Enter the number of row: "))
        print("First " + str(n) + " rows of Pascal's triangle: ")
        Pascal(n)
    except ValueError:
        print("Entered wrong value. Please enter a number.")
        print()
