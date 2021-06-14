def Convert_To_String(string):
    item = list(string.split(" "))
    return item


# Driver code
str1 = "Tux  TuX is a penguin character and the official brand character of the LINUX kernel. Originally created as an entry  logo competition, TUX is the most commonly used icon for Linux , although different Linux distributions depict Tux in various styles. The character is used in many other lInux programs and as a general symbol of Linux ."
# print(Convert(str1))
List = Convert_To_String(str1)

counter = 0
dic = {}
for i in range(len(List)):
    if List[i].istitle():
        List[i] = List[i].upper()
        #print(List[i])
#for i in range(len(List)):
#	print(List[i])

for i in range(0,len(List)):
    if List[i].isupper():
        if List[i] in dic:
            dic[List[i]] += 1
        else:
            dic[List[i]] = 1
#print(dic)


def search(dic, val):
    keysList = []
    itemsList = dic.items()
    for item in itemsList:
        if item[1] == val:
            keysList.append(item[0])
    return keysList
print("Enter number")
val = int(input())
print(search(dic, val))
