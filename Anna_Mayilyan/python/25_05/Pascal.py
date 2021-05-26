n = int(input("n= "))
row = []
for i in range(n):
    row.append( [] )
    row[i].append(1)
    for j in range(1, i):
        row[i].append(row[i - 1][j - 1] + row[i - 1][j])
    if (n != 0):
        row[i].append(1)

print(row)
