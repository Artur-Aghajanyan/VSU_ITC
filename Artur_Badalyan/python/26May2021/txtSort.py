from modul import *


lst = [
"a23 34 54",
"w23 14 54",
"w21 87 47",
"789 47 65",
"m72 jog mid",
"d47 jog mid",
"d31 fog mid",
"x35 45 27",
"a51 alps glow",
"a21 alps blow"]


numbers=[]
words=[]
lenn=len(lst)

print("Before")
printLst(lst)

clearingList(lst)
appendLists(lst,numbers,words)

sortingWord(words)
sortingNum(numbers)
lst = words + numbers

print("After")
printLst(lst)



