def perfect(n):
    sum = 0
    for i in range(1,n):
       if n % i == 0:
           sum+=i
    if sum == n:
        print(n," is a Perfect number!")
        return
    print(n," is not a Perfect number!")

while True:
    try:
        n = int(input("Write number for checking! - "))
    except(ValueError):
        print("plz, Write number!")
        continue
    if n < 1 or n > 10000:
        print("plz, write number between 1-10000")
        continue
    break
perfect(n)
