
def perfectNum (num):
    sum=0
    for i in range(1,num):
        if num % i == 0:
            sum = sum + i
    
    if num == sum:
        print(num,"is a perfect number")
    else:
        print(num,"is not a perfect number")


print("Write number for check is a perfect number or not.")
num=input()

if num.isdigit():
     perfectNum(int(num))
else:
     print("User input is string or small then 0")

