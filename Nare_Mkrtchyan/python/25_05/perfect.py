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
    if num <= 0:
        print("Number must be natuaral.")
        return
    if num > 100000000:
        print("Number must be <= 100000000.")
        return
    my_sum = 0
    for i in range(1,n-1):
        if n%i == 0:
            my_sum = my_sum + i
    if n == my_sum:
        print(n, "is perfect number")
    else:
        print(n, "is not perfect number")

print("Enter natural number(<=100000000) to check if it is perfect or not:")
num = input()
if check(num):
    num = int(num)
    perf(num)
elif num == "":
    print("Number can't be empty.")
else:
    print(num, "is not natural number. Enter number.")
