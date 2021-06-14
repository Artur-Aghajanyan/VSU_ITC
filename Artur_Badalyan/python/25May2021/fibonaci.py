import sys

def fibonaci (n):
    a=0
    b=1

    if n == 0:
        print("Your nth fibonaci number ",a)
        return
    elif n == 1:
        print("Your nth fibonaci number ",b)
        return
    else:
        n = n + 1
        for i in range(2,n):
            c = a + b
            a = b
            b = c
        print("Your nth fibonaci number ", b)


def checkInput(n):
    if n.isdigit():
        if int(n) > 2147483647:
            print("User input big in int limit")
            sys.exit()
    else:
        print("User input is string or small then 0")
        sys.exit()




n = input("Please enter number ")
checkInput(n)
fibonaci(int(n))

