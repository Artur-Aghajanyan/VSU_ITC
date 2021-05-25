def Perfect(n):
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
    break
Perfect(n)
