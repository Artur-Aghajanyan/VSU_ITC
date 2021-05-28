
lst = [
"wz3 34 54",
"mi2 jog mid",
"x35 45 27",
"a51 alps cow",
"a21 alps blow"]


lenn=len(lst)

def clearingList(lst):

    lenn=len(lst)
    l=0
    while l in range(lenn):
        print(lst[l][0] + lst[l][1] + lst[0][2])
        if not lst[l][0].isdigit() and lst[l][1].isdigit() and lst[l][2].isdigit():
            print(".")
        else:
            del lst[l]
            lenn -= 1
        l = l + 1

def printLst(lst):
    for i in lst:
        print(i)
    print("\n")    

numbers=[]
words=[]

for i in range(lenn):
    if lst[i][-1].isdigit():
        numbers.append(lst[i])
    else:
        words.append(lst[i])


#sorting 
def sortingWord(words):
    for i in range(len(words)-1):
        if words[i][0] > words[i+1][0]:
            temp = words[i]
            words[i] = words[i+1]
            words[i+1] = temp

        if words[i][0] == words[i+1][0]:
            split1 = words[i].split(" ")
            split2 = words[i+1].split(" ")
            for j in range(1,len(split1)):
                if split1[j] > split2[j]:
                    temp = words[i]
                    words[i] = words[i+1]
                    words[i+1] = temp


def sortingNum(numbers):
    for i in range(len(numbers)-1):
        if numbers[i][1] > numbers[i+1][1]:
            temp = numbers[i]
            numbers[i] = numbers[i+1]
            numbers[i+1] = temp
        elif numbers[i][2] > numbers[i+1][2]:
            temp = numbers[i]
            numbers[i] = numbers[i+2]
            numbers[i+2] = temp          

        if numbers[i][4] == numbers[i+1][4]:
            split1 = numbers[i].split(" ")
            split2 = numbers[i+1].split(" ")
            print(numbers[i][4], " @ ",numbers[i+1][4])
            for j in range(1,len(split1)):
                 if split1[j] > split2[j]:
                        temp = numbers[i]
                        numbers[i] = numbers[i+1]
                        numbers[i+1] = temp

print("Before")
printLst(lst)

sortingWord(words)
sortingNum(numbers)

lst = words + numbers

print("After")
printLst(lst)



