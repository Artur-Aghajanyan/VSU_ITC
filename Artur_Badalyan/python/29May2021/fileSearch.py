import pprint
from typing import Text
from modul import *

path = ""
inex = False

class bcolors:
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'



#Lists for consolidation and printing

searchFiles = []
listFindFiles = []
searchDir = []
listFindDir = []
listFindText = []

#Help print function

def helps():
     print(bcolors.WARNING + "\n-h or--help                                             Commands") 
     print("-f or --file    OR   -d or --directory                  For search file or directory (default --file)") 
     print("--path ./PATH/                                          Write PATH for search file or directory (default ./)")  
     print("-s or --search \"TextForSearch\"                          Write text for search in files") 
     print("֊֊include .txt                                          Which files to include in the search engine are missing by default") 
     print("֊֊exclude .txt                                          Which files not to include in the search is omitted by default."+bcolors.ENDC) 
      


def flags(findFiles,findDir,findText):
    global size
    global path
    global inex
    global searchFiles 
    global listFindFiles 
    global searchDir
    global listFindDir 
    global listFindText 

    path = "/"
    extension = ""

    try:
        for i in range(size):
            if sys.argv[i] in ("-h","--help"):
                helps()
                exit()
            elif sys.argv[i] == "--path":
                path = sys.argv[i+1]
            elif sys.argv[i] == "--include":
                extension = sys.argv[i+1]
                    
        for i in range(size):
            if sys.argv[i] == "--exclude":
                inex=True
                extension = sys.argv[i+1]     

        for i in range(1, size):
            if sys.argv[i] in ("-f","--file"):
                searchFiles.append(sys.argv[i+1])
                listFindFiles.append(findFiles(path,sys.argv[i+1],extension,inex))
                continue
            elif sys.argv[i] in ("-d","--directory"):
                searchDir.append(sys.argv[i+1])
                listFindDir.append(findDir(path,sys.argv[i+1]))
                continue
            elif sys.argv[i] in ("-s","--search"):
                listFindText.append((findText(path,sys.argv[i+1],extension,inex)))
                continue
            
    except Exception as e:
        print(bcolors.FAIL)
        print("\n","ERROR ",e)
        helps()
        exit()
       
def printLists():
    global path
    global searchFiles 
    global searchDir
    global listFindFiles 
    global listFindDir 
    global listFindText


    print(bcolors.OKGREEN+"Path is a ->",path,"\n"+bcolors.OKBLUE)

    if len(searchDir) == 0 and len(searchFiles) == 0:
        print(bcolors.FAIL + "Please search file or directory(It is a important)"+bcolors.OKBLUE)
        exit()
    
    if not len(listFindFiles) == 0:
        print("---Find files---")
        pprint.pprint(listFindFiles)
        print("\n")
    
    if not len(listFindDir) == 0:
        print("---Find directories---")    
        pprint.pprint(listFindDir)
        print("\n")
    
    if not len(listFindText) == 0:
        print("---Find text---")
        pprint.pprint(listFindText)
        print("\n")


flags(findFiles,findDir,findText)

printLists()

