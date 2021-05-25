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
    if n==1:
        list2.append(1)
        print(list2)
        return
    elif n==2:
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
        
        for c in range(1,n-1):
            list2.append(1)
            for i in range(0,len(list1)-1):
                list2.append(list1[i]+list1[i+1]) 
            list2.append(1)
            list1=list2
            print(list1)
            list2=[]
        return

print("Enter row number to get first n rown of Pascal triangle: ")
num=input()
if check(num):
    num=int(num)
    pascal(num,list2)
else:
    print(num,"is not number. Enter number.")
