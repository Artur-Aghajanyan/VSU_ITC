text = ""
while text == "":
    text = input()
line = text.split(". ")
k = {}
for list_element in line:
    x = list_element.split()
    d = {}
    for i in x:
        if ord(i[0]) < ord("a"):
            if i[1 : len(i)].isupper() or i[1 : len(i)].islower():
                i = i.upper()
                if i in d.keys():
                    d[i] = d[i] + 1
                else:
                    d[i] = 1
    if d[x[0].upper()] == 1:
        if x[0].upper() not in k.keys:
            del d[x[0].upper()]
    for p in d.keys():
        if p in k.keys():
            k[p] = k[p] + 1
        else:
            k[p] = 1
value = 0
d.clear()
for p in k.keys():
    if k[p] > value:
        d.clear()
        value = k[p]
        d[p] = k[p]
    elif k[p] == value:
        d[p] = k[p]
        print(d)

