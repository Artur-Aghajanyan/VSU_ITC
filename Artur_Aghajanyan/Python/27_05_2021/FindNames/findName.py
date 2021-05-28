from modules import *
text = open("text.txt", "r")
textList = []
content = text.read()
text.close()

content = content.replace("\n", "")
textList = content.split(" ")

dictionaryForAllItems = {}

index = 0
size = len(textList)


for i in range(1, size):
    if textList[i] == "":
        continue
    if textList[i][len(textList[i]) - 1] == "?" or textList[i][len(textList[i]) - 1] == "!" and textList[i][0].islower():
        index = i
        continue
    if  len(textList[i]) == 2 and textList[i][len(textList[i])-2].isupper() and textList[i][len(textList[i]) - 1] == ".":
        index = i
        continue
    if len(textList[i]) > 3 and textList[i][(len(textList[i])) - 1] == "." or textList[i][len(textList[i]) - 1] == "?" or \
            textList[i][len(textList[i]) - 1] == "!" and textList[i][0].islower():
        index = i
        continue
    
    if index == 0 and len(textList[i]) > 2 and textList[i][0].isupper():
        index = 0
        addItemsInDictionary(textList[i], dictionaryForAllItems)
        
    index = 0

res = sortDictionary(dictionaryForAllItems)
printNCountNames(res)





