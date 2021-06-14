n = int(input("n = "))
sumofDivisors = 0
for i in range(1, n):
    if(n % i == 0):
        sumofDivisors = sumofDivisors + i
if (sumofDivisors == n):
    print("Number", n, "is perfect.")
else:
    print("Number", n, "is not perfect.")
