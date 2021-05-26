n = int(input(" Enter number: "))
S = 0
for i in range(1, n):
    if(n % i == 0):
        S = S + i
if (S == n):
    print(" %d is a Perfect Number" %n)
else:
    print(" %d is not a Perfect Number" %n)
