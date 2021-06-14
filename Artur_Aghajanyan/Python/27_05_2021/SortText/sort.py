from modules import *

strings = []
listWithLetters = []
listWithNumbers = []
sizeString = input("String size (default = 5): ")

if not sizeString.isdigit() or sizeString.isdigit() < 1:
    sizeString = 5
    
print("String size =", sizeString)
for i in range(int(sizeString)):
    validateUserInput(strings)

makeTwoListFromOneByValue(strings, listWithNumbers, listWithLetters)
sortStringList(listWithLetters)
sortNumberList(listWithNumbers)
print("---------------")
print("Default List")
print(strings)
res = [*listWithLetters, *listWithNumbers]
print("***********")
print("Sorted List")
print(res)
