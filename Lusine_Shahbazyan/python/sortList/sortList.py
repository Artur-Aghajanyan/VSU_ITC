def sortNumericList(myList):
    size = len(myList)
    for i in range(size - 1):
        for j in range(size - i - 1):
            if myList[j][1] > myList[j + 1][1]:
                temp = myList[j]
                myList[j] = myList[j + 1]
                myList[j + 1] = temp
            if myList[j][2] > myList[j + 1][2] and myList[j][1] == myList[j + 1][1]:
                temp = myList[j]
                myList[j] = myList[j + 1]
                myList[j + 1] = temp
                
    for i in range(size - 1):
        for j in range(size - i - 1):
            if myList[j].split()[0][1] == myList[j + 1].split()[0][1] and myList[j].split()[0][2] == myList[j + 1].split()[0][2]:
                word1 = int(myList[j].split()[1])
                word2 = int(myList[j + 1].split()[1])
                if word1 > word2:
                    temp = myList[j]
                    myList[j] = myList[j + 1]
                    myList[j + 1] = temp 
    
            if int(myList[j].split()[1]) == int(myList[j + 1].split()[1]):
                word1 = int(myList[j].split()[2])
                word2 = int(myList[j + 1].split()[2])
                if word1 > word2:
                    temp = myList[j]
                    myList[j] = myList[j + 1]
                    myList[j + 1] = temp 
           
def sortWords(word1, word2, myList, j):
    if len(word1) > len(word2):
        temp = myList[j]
        myList[j] = myList[j + 1]
        myList[j + 1] = temp
    if len(word1) == len(word2):
        sizeWord = len(word1)
        if  word1[0] > word2[0]:
            temp = myList[j]
            myList[j] = myList[j + 1]
            myList[j + 1] = temp
        sizeWord -= 1 
        if sizeWord > 0:
                    if word1[0] == word2[0] and word1[1] > word2[1]:
                        temp = myList[j]
                        myList[j] = myList[j + 1]
                        myList[j + 1] = temp
                    sizeWord -= 1
                    if sizeWord > 0:
                        if word1[0] == word2[0] and word1[1] ==  word2[1] and word1[2] >  word2[2]:
                            temp = myList[j]
                            myList[j] = myList[j + 1]
                            myList[j + 1] = temp
                            
def sortLiteralList(myList):
    size = len(myList)
    for i in range(size - 1):
        for j in range(size - i - 1):
            if myList[j][0] > myList[j + 1][0]:
                temp = myList[j]
                myList[j] = myList[j + 1]
                myList[j + 1] = temp
    for i in range(size - 1):
        for j in range(size - i - 1):            
            if myList[j][0] == myList[j + 1][0]:
                word1 = myList[j].split()[1]
                word2 = myList[j + 1].split()[1]
                sortWords(word1, word2, myList, j)
                if word1 == word2:
                    word3 = myList[j].split()[2] 
                    word4 = myList[j + 1].split()[2]
                    sortWords(word3, word4, myList, j)
        
   
        
    

def inputValidation(string):
    line = string.split()
    if len(line) != 3:
        print("Format of string will be: 'key word word' ")
        return False
    if string[0].isalpha() is False:
        print("First character of the string must be a letter a - z ")
        return False
    if string[1].isnumeric() is False or string[2].isnumeric() is False:
        print("Structure of first key is ' letter number number '  for exemple 'a13' ") 
        return False
    if line[1].isalpha() is False:
        if line[2].isalpha() is True or line[1].isnumeric() is False:
            print("The second and third words must be identical or numeric or literal ' 123 651' or 'fgh nmk")
            return False
    if line[2].isalpha() is False:
        if line[1].isalpha() is True or line[2].isnumeric() is False:
            print("The second and third words must be identical or numeric or literal ' 123 651' or 'fgh nmk") 
            return False
    return True 
    
numericList = []
literalList = []
print("Examples of inputting strings is: d12 123 21  or m03 hnj kmn ")
print("Enter strings:")
while True:
    string = input()
    if string == "#":
        break
    if(inputValidation(string)):
        if string[-1].isalpha():
            literalList.append(string)
        else:
            numericList.append(string)

sortLiteralList(literalList)
sortNumericList(numericList)

for i in range(len(numericList)):
    literalList.append(numericList[i])

for i in range(len(literalList)):
    print(literalList[i])



