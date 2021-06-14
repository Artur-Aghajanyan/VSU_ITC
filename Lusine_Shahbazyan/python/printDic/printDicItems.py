import operator

def printResult(dic, n):
     sortedDic = {}
     sortedDic = dict(sorted(dic.items(), key=operator.itemgetter(1), reverse=True))
     for key, value in dict(sortedDic).items():
         if value == 1:
             del sortedDic[key]
     for key,value in sortedDic.items():
         if n == 0:
             break
         print(key,':', value)
         n -= 1

def checkWordInLine(line, word, j):
    for i in range(j-1, -1, -1):
        if word == line[i] or word == line[i].upper():  
            return False
    return True

def checkWords():
    for i in range(len(myList)):
        lineForChecking = [] 
        lineForChecking = myList[i].split()
        for j in range(len(lineForChecking)):
            wordForChecking = lineForChecking[j]
            if((wordForChecking[0].isupper() and wordForChecking[1:].islower()) or wordForChecking.isupper()):
                wordForChecking = wordForChecking.upper()
                if(checkWordInLine(lineForChecking, wordForChecking, j)):
                    if wordForChecking not in dictionary.keys():
                        dictionary[wordForChecking] = 1
                    else:
                        dictionary[wordForChecking] += 1

myList = ["text:A Tux is a penguin character and the official brand",
          "character of the LINUX kernel F first_three_items For For",
          "Originally created as an entry to a Linux logo competition",
          "TUX the Most commonly  used Linux icon C TUX",
          "Linux  although Most Linux different Linux distributions",
          "depict TUx  in various styles. The MOST character is used in",
          "many other lInux programs and asa general symbol of Linux"]

dictionary = {}
print("Enter count of most repeated words:")
n = input()
while  n.isdigit() == False:
    print ("Enter number")
    n = input()
else:
    n = int(n)
    checkWords()
printResult(dictionary, n)

