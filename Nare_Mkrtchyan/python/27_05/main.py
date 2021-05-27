print("Enter N")
N = input()
while not N.isdigit():
    print ("Enter number")
    N = input()
else:
    N = int(N)

f = open("file", "r")
list1 = []
list2 = []
count = []
all = f.readlines()
for str1 in all:
    d = str1.split()
    for j in range(0,len(d)):
        if (d[j][0] == "." or d[j][0] == ",") and len(d[j]) != 1:
            d[j] = d[j][1:]
        if (d[j][-1] == "." or d[j][-1] == ",") and len(d[j]) != 1:
            d[j] = d[j][:-1]
        if d[j][0].isupper() or d[j].isupper():
            if len(list1) == 0:
                if j != 0:
                    d1 = d[j].upper()
                    list1.append(d1)
                    list2.append(d1)
                    count.append(1)
            else:
                check1 = False
                check2 = False
                for k in range(0,len(list1)):
                    d1 = d[j].upper()
                    for a in list2:
                        if d1 == a:
                            check2 = True
                            break
                    if d1 == list1[k] and not check2:
                        list2.append(d1)
                        count[k] = count[k] + 1
                        check1 = True
                        break
                if not check1 and not check2 and j!=0:
                    list1.append(d1)
                    list2.append(d1)
                    count.append(1)
    list2 = []

my_max = max(count)
for i in range(0,len(count)):
    if count[i] == my_max and N != 0:
        print(list1[i], ": ", my_max)
        N = N - 1
