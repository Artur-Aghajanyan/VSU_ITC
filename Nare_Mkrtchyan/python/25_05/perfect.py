def check(num):
"""
    Check function checks if user input is number or not. If it is number returns true, otherwise returns false.
"""

    try:
        int(num)
        return True
    except ValueError:
        return False

def perf(n):
    """
    perf function checks if user input is perfect number or not.
    """
    mysum=0
    for i in range(1,n-1):
        if n%i==0:
            mysum=mysum+i
    if n==mysum:
        print(n, "is perfect number")
    else:
        print(n,"is not perfect number")

print("Enter number to check if it is perfect or not:")
num=input()
if check(num):
    num=int(num)
    perf(num)
else:
    print(num,"is not number. Enter number.")
