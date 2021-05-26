def fibonacci(n):
    numbers = [0,1]
    if n > 2:
        for i in range(2,n):
            numbers.append(numbers[i-2]+numbers[i-1])
    print("Number is ",numbers[n-1])
while True:
    try:
        n = int(input("Write index of fibonacci number! - "))
    except(ValueError):
        print("plz, Write number!")
        continue
    if n < 1 or n > 10000:
        print("Plz, write number bitwin 1-10000")
        continue
    break
fibonacci(n)
