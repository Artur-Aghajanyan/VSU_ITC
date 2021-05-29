def clearingList(List):
    l=0
    while l in range(len(List)):
        if  List[l][0].isdigit() or not List[l][1].isdigit() or not List[l][2].isdigit():
            List.pop(l)   
        l += 1
        

def printLst(lst):
    for i in lst:
        print(i)
    print("\n")    


def appendLists(lst,numbers,words):
    for item in lst:
        if item[-1].isdigit():
            numbers.append(item)
        else:
            words.append(item)


#sorting 
def sortingWord(words):
    for k in range(len(words)-1):
        for i in range(len(words)-k-1):
            if words[i][0] > words[i+1][0]:
                words[i],words[i+1] = words[i+1],words[i]
            elif words[i][0] == words[i+1][0]:
                if words[i][1] > words[i+1][1]:
                    words[i],words[i+1] = words[i+1],words[i]
                elif words[i][1] == words[i+1][1]:
                    if words[i][2] > words[i+1][2]:
                        words[i],words[i+1] = words[i+1],words[i]
                    elif words[i][2] == words[i+1][2]:
                        split1 = words[i].split(" ")
                        split2 = words[i+1].split(" ")
                        for j in range(1,len(split1)):
                            if split1[j] > split2[j]:
                                words[i],words[i+1] = words[i+1],words[i]


def sortingNum(numbers):
    for k in range(len(numbers)-1):
        for i in range(len(numbers)-k-1):
            if numbers[i][1] > numbers[i+1][1]:
                numbers[i],numbers[i+1] = numbers[i+1],numbers[i]
            elif numbers[i][1] == numbers[i+1][1]:
                if numbers[i][2] > numbers[i+1][2]:
                    numbers[i],numbers[i+1] = numbers[i+1],numbers[i]
                elif numbers[i][2] == numbers[i+1][2]:
                    if numbers[i][0] > numbers[i+1][0]:
                        numbers[i],numbers[i+1] = numbers[i+1],numbers[i]
                    elif numbers[i][0] == numbers[i+1][0]:
                        split1 = numbers[i].split(" ")
                        split2 = numbers[i+1].split(" ")
                        for j in range(1,len(split1)):
                            if split1[j] > split2[j]:
                                numbers[i],numbers[i+1] = numbers[i+1],numbers[i]


