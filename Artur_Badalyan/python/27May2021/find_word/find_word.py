from modul import sorting,counter,printDict

f = open("text","r")  
lst=f.read()
f.close()
lst = lst.replace("\n", "");
lst=lst.split(" ")

foundList=[] 
Dict={}

for i in lst:
    if len(i) == 2 and i[len(i)-1] == ".":
        continue
    if i == "":
        continue

    if i[0].isupper() or i.isupper():
        i = i.replace(".","")
        i = i.replace(",","")
        foundList.append(i)
       
 
#The number of repetitions of words is added to the dictionary
for i in foundList:
    counter(i,Dict)

#Sorting dicionary
Dict=sorting(Dict)

print("Write number for print nth words")
n = int(input())

#Prints the dictionary and checks the imported cost at the same time
printDict(Dict,n)

