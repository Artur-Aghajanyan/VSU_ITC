def checkInt(num):
    """
    Check function checks if user input is intager or not. If it is intager returns true, otherwise returns false. 
    """
    try:
        int(num)
        return True
    except ValueError:
        return False

def checkFloat(num):
    """
    Check function checks if user input is float or not. If it is float returns true, otherwise returns false. 
    """
    try:
        float(num)
        return True
    except ValueError:
        return False

def fibonachi(n):
    """
    fibonachi function returns n'th fibonachi number.
    """
    if n==0:
        return 0
    if(n==1):
        return 1
    if(n==2):
        return 1
    if(n>2):
        return fibonachi(n-1)+fibonachi(n-2)

def start():
    """
    start function calls check and fibonachi functions
    """
    num=input()
    if checkInt(num):
        num=int(num)
        if num>40:
            print(num,">40. Enter number less or equal then 40(Type Ctrl c to exit).")
            start()
        elif num<0:
            print(num,"is negative number. Enter non negative intager(Type Ctrl c to exit).")
            start()
        else:
            print(num,"'th fibonachi item is: ", fibonachi(num))
    elif checkFloat(num):
        print(num,"is not intager. Enter intager(Type Ctrl c to exit)")
        start()
    else:
        if num=="":
            print("Number can't be empty.Enter number(Type Ctrl c to exit)")
        else:
            print(num,"is not number. Enter number(Type Ctrl c to exit).")
        start()

print("Enter only non negative intager (<40) and get the corresponding Fibonacci number:")
start()
