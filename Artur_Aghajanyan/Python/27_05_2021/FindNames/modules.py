def addItemsInDictionary(item, dictionaryForAllItems):
    if item[-1] == ".":
        item = item.replace(".", "")
    if item[-1] == ";":
        item = item.replace(";", "")
    if item[-1] == ":":
        item = item.replace(":", "")
    if item[-1] == "\"":
        item = item.replace("\"", "")
    if item[-1] == ",":
        item = item.replace(",", "")
    if item[-1] == "?":
        item = item.replace("?", "")
    if item[-1] == "!":
        item = item.replace("!", "")
    if item.upper() == "THE" or item.upper() == "I" or item.upper() == "HE" or item.upper() == "SHE":
        return 0
    if len(dictionaryForAllItems) == 0:
        dictionaryForAllItems[item] = 1
        return 0
    
    for key in dictionaryForAllItems:
        if key.upper() == item.upper():
            dictionaryForAllItems[key] += 1
            return 0
    dictionaryForAllItems[item] = 1

def sortDictionary(dictionaryForAllItems):
    marklist = list(dictionaryForAllItems.items())
    l = len(marklist)
    for i in range(l - 1):
        for j in range(i + 1, l):
            if marklist[i][1] < marklist[j][1]:
                t = marklist[i]
                marklist[i] = marklist[j]
                marklist[j] = t
    return dict(marklist)
         

def printNCountNames(sortedDictionaryForAllItems):
    n = input("How much name do you want to see? ")
    while not n.isdigit() or int(n) < 1:
        print("Your input is not corect.")
        print("It is string or small than 0.")
        n = input("How much name do you want to see? ")
    
    n = int(n)
    print("-------------------")
    print("All names.")
    print(sortedDictionaryForAllItems)
    print("*******************")
    counter = 0
    for key, value in sortedDictionaryForAllItems.items():
        counter += 1
        if n == 0:
            break
        print(counter, ")  Name - ", key, " Found - ", value)
        n -= 1
    
    if n != 0:
        print("End")
    else:
        print("...")
    print("********************")



