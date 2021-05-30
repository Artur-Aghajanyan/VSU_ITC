
import sys,os,re

size = len(sys.argv)


#Find files function

def findFiles(searchPath,fileName,end, inex):
    result = []
    if inex:
        for root, dir, files in os.walk(searchPath):
            for item in files:
                if not item.endswith(end) and fileName in item:
                    result.append(os.path.join(root, item))
        return result
    else:
        for root, dir, files in os.walk(searchPath):
            for item in files:
                if item.endswith(end) and fileName in item:
                    result.append(os.path.join(root, item))
        return result

#Find directory function   

def findDir(searchPath,dirName):
   result = []
   for root, dir, files in os.walk(searchPath):
      if dirName in dir:
          result.append(os.path.join(root, dirName))
   return result

#Find text in files

def findText(searchPath,text,end, inex):
    result = []
    
    if inex:
        for root, dir, files in os.walk(searchPath):
            for fileName in files:
                try:
                    f = open(os.path.join(root, fileName),"r")
                    res = re.findall(text, f.read())
                    if res and not fileName.endswith(end):
                        result.append(os.path.join(root, fileName))
                except Exception:
                    continue
    else:    
        for root, dir, files in os.walk(searchPath):
            for fileName in files:
                try:
                    f = open(os.path.join(root, fileName),"r")
                    res = re.findall(text, f.read())
                    if res and fileName.endswith(end):
                        result.append(os.path.join(root, fileName))
                except Exception:
                    continue

    return result
