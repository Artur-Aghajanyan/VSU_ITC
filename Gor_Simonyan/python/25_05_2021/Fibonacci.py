def Fibonacci(n):
    Numbers = [0,1]
    if n > 2:
        for i in range(2,n):
            Numbers.append(Numbers[i-2]+Numbers[i-1])
    print("Number is ",Numbers[n-1])
while True:
    try:
        n = int(input("Write index of fibonacci number! - "))
    except(ValueError):
        print("plz, Write number!")
        continue
    break
Fibonacci(n)
