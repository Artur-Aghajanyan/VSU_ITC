def is_perfect_num(n):
    s = 0
    for i in range(1, n):
        if n % i == 0:
            s = s + i
    if s == n:
        print(n, "-is perfect number")
    else :
        print(n, "-isn't perfect number")
is_perfect_num(8128)
