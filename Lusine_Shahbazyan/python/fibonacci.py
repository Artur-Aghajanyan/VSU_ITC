n = int(input("n = "))
FibonacciArray = [0,1]
  
def findFibonacciNumber(n):
    if n < 0:
        print("Incorrect input")
    elif n == 1:
        return FibonacciArray[0]
    elif n == 2:
        return FibonacciArray[1]
    else:
        fibNumber = findFibonacciNumber(n-1)+findFibonacciNumber(n-2)
        FibonacciArray.append(fibNumber)
        return fibNumber
  
  
print(findFibonacciNumber(n))
