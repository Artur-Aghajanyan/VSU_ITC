import sys


def perfectNum (num):
    sum=0
    for i in range(1,num):
        if num % i == 0:
            sum = sum + i
    
    if num == sum:
        print(num,"is a perfect number")
    else:
        print(num,"is not a perfect number")


def checkInput(n):
      if n.isdigit():
          if int(n) > 2147483647:
              print("User input big in int limit")
              sys.exit()
      else:
          print("User input is string or small then 0")
          sys.exit()


print("Write number for check is a perfect number or not.")
num=input()

checkInput(num)
perfectNum(int(num))
