list1 = ["wz3 34 54","mi2 jog mid","x5 45 27","a1 alps cow", "a1 alps blow"]
let_counter = 0
print("List before sorting:")
print(list1)
def sort_let_num():
    """
    sort_let_num function brings left strings with letters.
    """
    list2 = []
    for i in range(5):
        data1 = list1[i].split()
        dig = False
        for j in data1[1]:
            if j.isdigit():
                list2.append(list1[i])
                dig = True
                break
        if dig:
            continue
        else:
            for j in data1[2]:
                if j.isdigit():
                    list2.append(list1[i])
                    dig = True
                    break
            if dig:
                continue
            else:
                list2.insert(0,list1[i])
                global let_counter
                let_counter+=1
    return list2

def letter():
    """
    letter function sorts letter part of list.
    """
    for k in range(0, let_counter):
        for i in range(0,let_counter-k-1):
            list2 = []
            data1 = list1[i].split()
            data2 = list1[i+1].split()
            for j in range(0,3):
                if len(data1[j]) == len(data2[j]):
                    if data1[j] > data2[j]:
                        helper = list1[i]
                        list1[i] = list1[i+1]
                        list1[i+1] = helper
                        break
                elif len(data1[j]) > len(data2[j]):
                    helper = list1[i]
                    list1[i] = list1[i+1]
                    list1[i+1] = helper
                    break
                else:
                    break

def number():
    """
    number function sorts number part of list.
    """
    for k in range(let_counter-1, len(list1)):
        for i in range(let_counter-1,len(list1)-1-k):
            data1 = list1[i].split()
            d11 = ""
            d21 = ""
            d12 = ""
            d22 = ""
            data2 = list1[i+1].split()
            for j in range(0, len(data1[0])):
                if j.isdigit():
                    d11+=j
                else:
                    d12+=j
            for j in range(0, len(data2[0])):
                if j.isdigit():
                    d21+=j
                else: 
                    d22+=j
            d11 = int(d11)
            d21 = int(d21)
            if d11 > d21:
                helper = list1[i]
                list1[i] = list1[i+1]
                list1[i+1] = helper
                break
            elif d11 == d21:
                if d12 > d22:
                    helper = list1[i]
                    list1[i] = list1[i+1]
                    list1[i+1] = helper
                    break
                for j in range(1,3):
                    for c in range(0, len(data1[j])):
                        if c.isdigit():
                            d11+=c
                        else:
                            d12+=c
                    for c in range(0, len(data2[c])):
                        if c.isdigit():
                            d21+=c
                        else: 
                            d22+=c
                    if d12 == d21:
                        if c == 1:
                            d1 = d12
                            d2 = d22
                            continue
                        elif d1 > d2 or d12 > d22:
                            helper = list1[i]
                            list1[i] = list1[i+1]
                            list1[i+1] = helper
                            break

list1 = sort_let_num()
letter()
number()
print("\nList after sorting:")
print(list1)
