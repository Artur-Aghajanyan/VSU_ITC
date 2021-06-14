def getUserInput():
    print("String must be like this: w32 ass asd 'or' a42 45 541")
    userString = input("Input your string: ")
    return userString

def checkWord(splitedInput):
    validType = ""
    if splitedInput[1][len(splitedInput[1]) - 1].isdigit():
        validType = "number"
    else:
        validType = "string"
    for i in range(len(splitedInput[1]) - 1):
        if validType == "number" and not splitedInput[1][i].isdigit():
            return False
        elif validType == "string" and splitedInput[1][i].isdigit():
            return False
    for i in range(len(splitedInput[2])):
        if validType == "number" and not splitedInput[2][i].isdigit():
            return False
        elif validType == "string" and splitedInput[2][i].isdigit():
            return False

def validateUserInput(strList):
    res = False
    while res == False:
        inputValue = getUserInput()
        splitedInput = inputValue.split(" ")
        
        if inputValue == "" or len(splitedInput) != 3 or splitedInput[0] == "" or splitedInput[1] == "" or\
        splitedInput[2] == "" or len(splitedInput[0]) != 3 or splitedInput[0][0].isdigit() or\
        not splitedInput[0][1].isdigit() or not splitedInput[0][2].isdigit():
            print("Your input is not correct!")
            continue
        wordRes = checkWord(splitedInput)
        if wordRes == False:
            print("Your input is not correct!")
            continue
        res = True
    strList.append(inputValue)
    print("\n", strList, "\n")


def makeTwoListFromOneByValue(listAll, numberList, stringList):
    size = len(listAll)
    for i in range(0, size):
        if listAll[i][-1].isdigit():
            numberList.append(listAll[i])
        else:
            stringList.append(listAll[i])

def sortByWord(item1, item2, index):
    if len(item1[index]) > len(item2[index]):
        return item2
    elif len(item1[index]) == len(item2[index]):
        for i in range(len(item1[index])):
            if item1[index][i] > item2[index][i]:
                return item2
            elif item1[index][i] < item2[index][i]:
                return item1
        return 0
    else:
        return item1

def sortStringList(stringList):
    size = len(stringList)
    for i in range(size):
        for j in range(i + 1, size):
            if stringList[i][0] > stringList[j][0]:
                temp = stringList[j]
                stringList[j] = stringList[i]
                stringList[i] = temp
            elif stringList[i][0] == stringList[j][0]:
                if stringList[i][1] > stringList[j][1]:
                    temp = stringList[j]
                    stringList[j] = stringList[i]
                    stringList[i] = temp
                elif stringList[i][1] == stringList[j][1]:
                    if stringList[i][2] > stringList[j][2]:
                        temp = stringList[j]
                        stringList[j] = stringList[i]
                        stringList[i] = temp
                    elif stringList[i][2] == stringList[j][2]:
                        item1 = stringList[i].split(" ")
                        item2 = stringList[j].split(" ")
                        res = sortByWord(item1, item2, 1)
                        if res == item2:
                            temp = stringList[j]
                            stringList[j] = stringList[i]
                            stringList[i] = temp
                        elif res == 0:
                            res = sortByWord(item1, item2, 2)
                            if res == item2:
                                temp = stringList[j]
                                stringList[j] = stringList[i]
                                stringList[i] = temp

def sortNumberList(numberList):
    size = len(numberList)
    for i in range(size):
        for j in range(i + 1, size):
            if numberList[i][1] > numberList[j][1]:
                temp = numberList[i]
                numberList[i] = numberList[j]
                numberList[j] = temp
            elif numberList[i][1] ==  numberList[j][1]:
                if numberList[i][2] > numberList[j][2]:
                    temp = numberList[i]
                    numberList[i] = numberList[j]
                    numberList[j] = temp
                elif numberList[i][2] == numberList[j][2]:
                    if numberList[i][0] > numberList[j][0]:
                        temp = numberList[i]
                        numberList[i] = numberList[j]
                        numberList[j] = temp
                    elif numberList[i][0] == numberList[j][0]:
                        item1 = numberList[i].split(" ")
                        item2 = numberList[j].split(" ")
                        res = sortByWord(item1, item2, 1)
                        if res == item2:
                            temp = stringList[j]
                            stringList[j] = stringList[i]
                            stringList[i] = temp
                        elif res == 0:
                            res = sortByWord(item1, item2, 2)
                            if res == item2:
                                temp = stringList[j]
                                stringList[j] = stringList[i]
                                stringList[i] = temp

            


