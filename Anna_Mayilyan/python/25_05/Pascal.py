def Pascal(n):
    row = []
    for i in range(n):
        row.append([])
        row[i].append(1)
        for j in range(1, i):
            row[i].append(row[i - 1][j - 1] + row[i - 1][j])
        if (n != 0):
            row[i].append(1)
    for word in row:
        print(word)

try:
    n = int(input("Enter the number "))
    Pascal(n)
except ValueError:
    print("It is not an integer number!")

