import re


def key_count(index):
    count1 = 0
    count2 = 0
    for i in arr[index]:
        if i.isalpha():
            count1 += 1 
    for j in arr[index+1]:
        if j.isalpha():
            count2 += 1
    if count1 > count2:
        arr[index], arr[index+1] = arr[index+1], arr[index]
        return True
    return False


def num_rows(index, i):
    x1 = re.findall(r'\d+', arr[index].split()[i])
    x2 = re.findall(r'\d+', arr[index+1].split()[i])
    if x1 > x2:
        arr[index], arr[index + 1] = arr[index + 1], arr[index]
        return True
    elif x1 < x2:
        return True
    return False


def key_len(index, i):
    if len(arr[index].split()[i]) > len(arr[index+1].split()[i]):
        arr[index], arr[index + 1] = arr[index + 1], arr[index]
        return True
    elif len(arr[index].split()[i]) == len(arr[index+1].split()[i]):
        return True
    return False


def is_num(index):
    for i in range(0, 3):
        if arr[index].split()[i].isnumeric():
            return True
    return False


def check():
    for j in range(0, len(arr)-1):
        for i in range(0, len(arr)-1):
            if is_num(i):
                if is_num(i+1):
                    if num_rows(i, 1):
                        continue
                    else:
                        if key_count(i):
                            continue
                        else:
                            for h in range(0, 3):
                                if key_len(i, h):
                                    break
                else:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
                continue
            elif is_num(i) is False and is_num(i+1):
                continue
            else:
                if key_count(i):
                    continue
                else:
                    for h in range(0, 3):
                        if key_len(i, h):
                            break
    print(arr)


arr = []
while True:
    arr.append(input("Input text - "))
    if arr[-1] == "exit":
        arr.pop()
        break
    if len(arr[-1].split()) != 3 or arr[-1].split()[0].isalpha() is True or arr[-1].split()[0].isnumeric() is True or arr[-1][0].isalpha() is not True:
        print("Error")
        arr.pop()
check()

