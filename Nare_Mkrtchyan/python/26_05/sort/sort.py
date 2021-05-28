list1 = []
let_counter = 0

def check_key(key):
    """
    check_key function checks keys syntax.
    """
    if len(key) != 3:
        print ("Key must contain 3 symbols")
        return False
    if key[0].isalpha():
        pass
    else:
        print("First symbol of key must be letter.")
        return False
    if key[1].isdigit() and key[2].isdigit():
        return True
    else:
        print("Secont and third symbols of key must be digits.")
        return False

def check_isdigit(w1,w2):
    """
    check_isdigit function checks whether word part is digit.
    """
    if w1.isdigit() and w2.isdigit():
        return True
    else:
        return False

def check_isalpha(w1,w2):
    """
    check_isalpha function checks whether word part is text.
    """
    for i in w1:
        if not i.isalpha():
            print("The word after key is not correct.")
            return False
    for i in w2:
        if not i.isalpha():
            print("The second word after key is not correct.")
            return False
    return True

def check(str1):
    """
    check function checks syntax and makes first point of sort.
    """
    if str1 == "":
        print("String can't be empty.")
        return False
    str_list = str1.split()
    if len(str_list) != 3:
        print("String must have 3 words")
        return False
    if not check_key(str_list[0]):
        return False
    if not check_isdigit(str_list[1], str_list[2]):
        if check_isalpha(str_list[1], str_list[2]):
            list1.insert(0,str1)
            global let_counter
            let_counter+=1
            return True
        else:
            return False
    else:
        list1.append(str1)
        return True
    return True

def swap(i):
    """
    swap function waps strings of list.
    """
    helper = list1[i]
    list1[i] = list1[i+1]
    list1[i+1] = helper

def word(i,data1,data2):
    """
    word function sorts via word part of strings.
    """
    for j in range(1,3):
        if len(data1[j]) == len(data2[j]):
            if data1[j] > data2[j]:
                swap(i)
                break
            elif data1[j] < data2[j]:
                break
        elif len(data1[j]) > len(data2[j]):
            swap(i)
            break
        else:
            break

def letter():
    """
    letter function sorts letter part of list.
    """
    for k in range(0, let_counter):
        for i in range(0,let_counter-k-1):
            data1 = list1[i].split()
            data2 = list1[i+1].split()
            if(data1[0] > data2[0]):
                swap(i)
            elif (data1[0] < data2[0]):
                continue
            else:
                word(i,data1,data2)

def number():
    """
    number function sorts number part of list.
    """
    for k in range(let_counter, len(list1)):
        for i in range(let_counter,len(list1)-1-(k-let_counter)):
            data1 = list1[i].split()
            data2 = list1[i+1].split()
            d1 = data1[0][1:]
            d2 = data2[0][1:]
            if d1 > d2:
                swap(i)
                continue
            elif d1 < d2:
                continue
            else:
                if data1[0][0] > data2[0][0]:
                    swap(i)
                    continue
                elif data1[0][0] < data2[0][0]:
                    continue
                else:
                    word(i,data1,data2)


print("Enter string count:")
list_len = input()
while not list_len.isdigit():
    print("Enter digit")
    list_len = input()
print("Enter strings.")
print("Structure of string: a12 asd dfg    or   f12 45 456")
i = int(list_len)
while i != 0:
    user_input = input()
    user_input = user_input.strip()
    if check(user_input):
        i = i - 1
    
letter()
number()
print("\nList after sorting:")
print(list1)
