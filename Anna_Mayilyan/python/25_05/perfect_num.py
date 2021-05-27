def is_Perfect(n):
    S = 0
    for i in range(1, n):
        if(n % i == 0):
            S = S + i
    if (S == n):
        print(" %d is a Perfect Number" % n)
    else:
        print(" %d is not a Perfect Number" % n)


try:
    n = int(input(" Enter number: "))
    is_Perfect(n)
except ValueError:
    print("Entered value is not an integer ")

