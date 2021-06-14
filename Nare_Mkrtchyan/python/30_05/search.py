import sys, getopt, os, re
from pathlib import Path
path = "./"
FILE = ""
DIR = ""
INCLUDE = ""
EXCLUDE = ""
SEARCH = ""
search_res = False
file_res = False
dir_res = False

#######  START
def start():
    if len(sys.argv) < 3 or len(sys.argv) > 13:
        print("Command line arguments are less or more then expected.")
        exit()

    set_var()

    if FILE == "" and DIR == "" and SEARCH == "" :
        print("Search or File or Directory parameter is necessary")
        exit()

    if FILE != "":
        print("FOUNDED files:")
        scanfile("/home")
        if not file_res:
            print("There are no files with given name.")

    if DIR != "":
        print("FOUNDED directories:")
        scandir("/home")
        if not dir_res:
            print("There are no directories with given name.")

    if SEARCH != "":
        print("SEARCH result:")
        path_to_search()
        scan(path)
        if not search_res:
            print("There are no matches.")

#####  SEARCH CHECK
def search_check(fname):
    if os.path.exists(fname):
        try:
            with open(fname,'r') as f:
                try:
                    for line in f:
                        for word in line.split():
                            x = re.search(r'\w' + SEARCH, word)
                            if x:
                                return True 
                except UnicodeDecodeError:
                    pass
        except OSError:
            pass


####### path to search
def path_to_search():
    for i in range(1,len(sys.argv)):
        if sys.argv[i] == "-p" or sys.argv[i] == "--path":
            global path
            path = sys.argv[i+1]
            break
    else:
        print("Search will be done in current directory.")


####### set variables
def set_var():
    for i in range(1,len(sys.argv)):
        if sys.argv[i] == "-s" or sys.argv[i] == "--search":
            global SEARCH
            SEARCH = sys.argv[i+1]
            #return
        elif sys.argv[i] == "-i" or sys.argv[i] == "--include":
            global INCLUDE
            INCLUDE = sys.argv[i+1]
        elif sys.argv[i] == "-e" or sys.argv[i] == "--exclude":
            global EXCLUDE
            EXCLUDE = sys.argv[i+1]
        elif sys.argv[i] == "-f" or sys.argv[i] == "--file":
            global FILE
            FILE = sys.argv[i+1]
        elif sys.argv[i] == "-d" or sys.argv[i] == "--directory":
            global DIR
            DIR = sys.argv[i+1]


####### INCLUDE 
def check_include(path):
    global INCLUDE
    if INCLUDE != "":
        s = str(path)
        x = re.search(r'\w' + INCLUDE, s)
        if x:
            return True
        else: 
            return False
    else:
        return True


####### EXCLUDE 
def check_exclude(path):
    global EXCLUDE
    if EXCLUDE != "":
        s = str(path)
        x = re.search(r'\w' + EXCLUDE, s)
        if x:
            return True
        else: return False
    else:
        return False




def scan(path):
    for path in Path(path).iterdir():
        if path.is_dir():
            scan(path)
        else:
            if search_check(path):
                if check_exclude(path):
                    continue
                if check_include(path):
                    global search_res
                    search_res = True
                    print(path)

def scanfile(path):
    for path in Path(path).iterdir():
        if path.is_dir():
            #global DIR
            #DIR = os.path.abspath(path)
            scanfile(path)
        else:
            global FILE
            if FILE != "":
                s = str(path)
                dir2 = os.path.basename(os.path.normpath(path))
                if (dir2 == FILE):
                    dir1 = os.path.abspath(path)
                    global file_res
                    file_res = True
                    print(dir1)
                    return

def scandir(path):
    for path in Path(path).iterdir():
        if path.is_dir():
            global DIR
            if DIR != "":
                s = str(path)
                dir2 = os.path.basename(os.path.normpath(path))
                if (dir2 == DIR):
                    dir1 = os.path.abspath(path)
                    global dir_res
                    dir_res = True
                    print(dir1)
            scandir(path)
start()
