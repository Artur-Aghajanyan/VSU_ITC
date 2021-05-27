import sys

def printPascal(n):

    for line in range(1, n + 1):
        C = 1;
        for i in range(1, line + 1):
            print(C,end=" ");
            C = int(C * (line - i) / i);
        print("");


def checkInput(n):
      if n.isdigit():
          if int(n) > 2147483647:
              print("User input big in int limit")
              sys.exit()
      else:
          print("User input is string or small then 0")
          sys.exit()


 
print("Write number for print nth pascal triangle")
n=input()

checkInput(n)
printPascal(int(n))


 
