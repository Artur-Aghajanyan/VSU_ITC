import collections
from modules import *


fileOrDirectory = "file"
fileOrDirectoryName = None
path = ["--path", "./"]
include = None
exclude = None
search = None
includes = None
excludes = None
includeList = []
searchList = []
fileOrDirectoryNameList = []

size = len(sys.argv)
if size == 1:
    print("\nThere are very few parameters to find the files or folder!")
    help()
    exit()

if sys.argv[1] in ("-h", "--help"):
    help()
    exit()

for i in range(1, size):
    if sys.argv[i] in ("--help", "-h"):
        help()
        exit()
    if sys.argv[i] in ("-d", "--directory"):
        fileOrDirectory = "directory"
    elif re.findall("^--path=", sys.argv[i]):
        path = sys.argv[i].split("=")
    elif re.findall("^-s=", sys.argv[i]) or re.findall("^--search=", sys.argv[i]):
        search = sys.argv[i].split("=")
    elif re.findall("^--include=", sys.argv[i]):
        include = sys.argv[i].split("=")
    elif re.findall("^--exclude=", sys.argv[i]):
        exclude = sys.argv[i].split("=")
    elif re.findall("^-n=", sys.argv[i]) or re.findall("^--name=", sys.argv[i]):
        fileOrDirectoryName = sys.argv[i].split("=")

if fileOrDirectoryName == None:
    print("There are very few parameters to find the files or folder!")
    help()
    exit()

if include != None:
    includes = include[1].split(",")
if exclude != None:
    excludes = exclude[1].split(",")


temp = []
if includes != None and excludes != None:
    size = len(includes)
    for i in range(size - 1):
        for ex in exclude:
            if includes[i] == ex:
                includes.pop(i)

# find file with given name
print("\n***************")
print('Find %ss With Name\n' %(fileOrDirectory))
fileOrDirectoryNameList = finder(fileOrDirectory, fileOrDirectoryName[1], path[1], excludes)
if len(fileOrDirectoryNameList) == 0:
    print("   *There is not File like that")
else:
    for i in range(len(fileOrDirectoryNameList)):
        print("   ", i+1, ")", fileOrDirectoryNameList[i])

# find file with includes
if include != None or exclude != None:
    print("\n\n***************")
    print("Find files With Includes\n")
    includeList = findFileWithInclude(path[1], includes, excludes)
    if len(includeList) == 0:
        print("   *There is not File like that")
    else:
        for i in range(len(includeList)):
            print("   ", i+1,")",includeList[i])

# Do search in file
if search != None:
    print("\n\n***************")
    print("Do search in files\n")
    searchList = searchTextInFile(path[1], search[1], excludes)
    if len(searchList) == 0:
        print("   *There is not File like that")
    else:
        for i in range(len(searchList)):
            print("   ", i+1, ")", searchList[i])


finalResult = []
#concat all results
if include != None and search != None:
    temp = list(set(fileOrDirectoryNameList) & set(includeList))    
    finalResult = list(set(temp) & set(searchList))
elif include != None and search == None:
    finalResult = list(set(fileOrDirectoryNameList) & set(includeList))    
elif include == None and search != None:
    finalResult = list(set(fileOrDirectoryNameList) & set(search)) 

print("\n\n\n---------------")
print("Final Result")
print("***************")

if includes == None and search == None:
    if len(fileOrDirectoryNameList) == 0:
        print("   *There is not File like that")
    else:
        for i in range(len(fileOrDirectoryNameList)):
            print("   ", i+1, ")", fileOrDirectoryNameList[i])
else:
    if len(finalResult) == 0:
        print("   *There is not File like that")
    else:
        for i in range(len(finalResult)):
            print("   ", i + 1, ")", finalResult[i])












