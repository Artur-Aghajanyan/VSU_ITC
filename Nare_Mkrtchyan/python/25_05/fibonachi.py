def check(num):
"""
    Check function checks if user input is number or not. If it is number returns true, otherwise returns false. 
 """
    try:
        int(num)
        return True
    except ValueError:
        return False

def fibonachi(n):
    """
    fibonachi function returns n'th fibonachi number.
    """
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
    if check(num):
        num=int(num)
        print(num,"'th fibonachi item is: ", fibonachi(num))
    else:
        print(num,"is not number. Enter number.")
        start()

start()
