g_list = []
def paskal(n):
    count = 0
    for i in range(0,n):
        s_list = []
        if count == 0:
            s_list.append(1)
            g_list.append(s_list)
        else:
            for j in range(0,count+1):
                if j-1 < 0:
                    x = g_list[i-1][j]
                elif j == count:
                    x = g_list[i-1][j-1]
                else:
                    x = g_list[i-1][j-1] + g_list[i-1][j]
                s_list.append(x)
            g_list.append(s_list)
        count+=1
    for i in g_list:
        print(i,'\n')
while True:
    try:
        n = int(input("Write number of row! - "))
    except(ValueError):
        print("plz, Write number!")
        continue
    if n < 1 or n > 100:
        print("plz, write number between 1-10000")
        continue
    break
paskal(n)
