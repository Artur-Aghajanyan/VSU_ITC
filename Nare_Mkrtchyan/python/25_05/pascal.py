import time
def check(num):
    """
    Check function checks if user input is number or not. If it is number returns true, otherwise returns false.
 """
    try:
        int(num)
        return True
    except ValueError:
        return False

list2 = []
def pascal(n,list2):
    """
    pascal function gets user input number, structs pascal triangle and prints it.
    """
    if n < 0 or n > 1000:
        print("Enter number in range (0,1000).")
        return
    if n > 50:
        print("It can take long time and you will get big numbers.(Type Ctrl c if you want to exit)")
        time.sleep(3)
    if n==0:
        list2.append(1)
        print(list2)
        return
    elif n==1:
        list2.append(1)
        print(list2)
        list2.append(1)
        print(list2)
        return
    else:
        list1 = [1]
        print(list1)
        list1.append(1)
        print(list1)
        
        for c in range(1,n):
            list2.append(1)
            for i in range(0,len(list1)-1):
                list2.append(list1[i]+list1[i+1]) 
            list2.append(1)
            list1=list2
            print(list1)
            list2=[]
        return

print("Enter row number to get first n rown of Pascal triangle: ")
print("Number should be intager in range (0,1000), if number > 50, you will get big numbers.")
num=input()
if check(num):
    num=int(num)
    pascal(num,list2)
elif num == "":
    print("Number can't be empty.")
else:
    print(num,"is not non negative intager number. Enter non negative intager number.")
