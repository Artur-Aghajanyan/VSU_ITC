import itertools 

def printResult(dic):
	sortedDic = {}
	sortedDic = sorted(dic.items(), key=lambda x: x[1], reverse=True)
	if ( n < len(sortedDic)):
	    for i in range(n):
	        print(sortedDic[i])
	else:
	    for i in range(len(sortedDic)):
	        print(sortedDic[i])
	        
def checkWordInLine(line, word):
    for i in range(len(line)):
        if word == line[i]:
            return False
    return True
    
def checkWords():
    for i in range(len(arr)):
        lineForChecking = []
        for j in range(len(arr[i].split())):
            lineForChecking = arr[i].split()
            wordForChecking = lineForChecking[j]
            if (wordForChecking[0].isupper() and wordForChecking[1:].islower()) or wordForChecking.isupper():
                wordForChecking = wordForChecking.upper()
                if(checkWordInLine(lineForChecking, wordForChecking)):
                    if wordForChecking not in dictionary.keys():
                        dictionary[wordForChecking] = 1
                    else:
                        dictionary[wordForChecking] += 1
                    
                
arr = ["text:A Tux is a penguin character and the official brand",
        "character of the LINUX kernel F first_three_items For  For ",
       "Originally created as an entry to a Linux logo competition ",
       "TUX is the most commonly TUX used Linux icon C Linux  although different Linux distributions ",
       "depict TUx in various styles. The character is used in many other lInux programs and as",
       "a general symbol of Linux "]
dictionary = {}
print("Enter count of most repeated words:")
n = input()
while  n.isdigit() == False:
    print ("Enter number")
    n = input()
else:
    n = int(n)
    checkWords()
printResult(dictionary)
