import sys, re, os, fnmatch
def help():
    print("\n-h or--help")
    print("-f or --file || -d or --directory(default --file).")
    print("--path=./PATH/ (default --path=./)")
    print("-n=FileName or --name=FileName for file name (Important).")
    print("-s=\"TextForSearch\" or --search=TextForSearch for search text in file regexp (Not Important).")
    print("֊֊include=NAME1,NAME2,NAME3,.. include files in search (Not Important)")
    print("֊֊exclude=NAME1,NAME2,NAME3,.. exclude files in search (Not Important)\n")


def finder(searchType, name, path, exclude):
    result = []
    if exclude != None:
        for root, dirs, files in os.walk(path):
            for fileName in files:
                for item in exclude:
                    if searchType == "file" and name in fileName and item != fileName:
                        result.append(os.path.join(root, fileName))
                    elif searchType == "directory" and name in dirs and item != fileName:
                        result.append(os.path.join(root, fileName))
        return result
    else:
        for root, dirs, files in os.walk(path):
            for fileName in files:
                if searchType == "file" and name in fileName:
                    result.append(os.path.join(root, fileName))
                elif searchType == "directory" and name in dirs:
                    result.append(os.path.join(root, fileName))
        return result

def searchTextInFile(path, text, exclude):
    result = []
    
    if exclude == None:
         for root, dirs, files in os.walk(path):
            for fileName in files: 
                try:
                    textFile = open(os.path.join(root, fileName), "r")
                    res = re.findall(text, textFile.read())
                    if res:
                        result.append(os.path.join(root, fileName))
                    else:
                        continue    
                except:
                    continue
                finally:
                     textFile.close()
    else:
        for root, dirs, files in os.walk(path):
            for fileName in files: 
                for item in exclude:
                    if item != fileName:
                        try:
                            textFile = open(os.path.join(root, fileName), "r")
                            res = re.findall(text, textFile.read())
                            if res:
                                result.append(os.path.join(root, fileName))
                            else:
                                continue    
                        except:
                            continue
                        finally:
                             textFile.close()
                       

    return result

def findFileWithInclude(path, include, exclude):
    result = []
    if exclude != None and include != None:
        for root, dirs, files in os.walk(path):
            for fileName in files:
                for item in exclude:
                    for inc in include:
                        if not re.findall(item, fileName) and re.findall(inc, fileName):
                            result.append(os.path.join(root, fileName))
        return result
    if exclude != None and include == None:
        for root, dirs, files in os.walk(path):
            for fileName in files:
                for item in exclude:
                    if not re.findall(item, fileName):
                        result.append(os.path.join(root, fileName))
        return result

    if exclude == None and include != None:
        for root, dirs, files in os.walk(path):
            for fileName in files:
                for inc in include:
                    if re.findall(inc, fileName):
                        result.append(os.path.join(root, fileName))
        return result
