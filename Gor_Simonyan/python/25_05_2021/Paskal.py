G_list = []
def Paskal(n):
    count = 0
    for i in range(0,n):
        S_list = []
        if count == 0:
            S_list.append(1)
            G_list.append(S_list)
        else:
            for j in range(0,count+1):
                if j-1 < 0:
                    x = G_list[i-1][j]
                elif j == count:
                    x = G_list[i-1][j-1]
                else:
                    x = G_list[i-1][j-1] + G_list[i-1][j]
                S_list.append(x)
            G_list.append(S_list)
        count+=1
    for i in G_list:
        print(i,'\n')
while True:
    try:
        n = int(input("Input number of row - "))
    except(ValueError):
        print("plz, Write number!")
        continue
    break
Paskal(n)
