def concat(str1,str2,sym):
    return str1+sym+str2

def rtrim(str1):
    c = len(str1) - 1
    while str1[len(str1)-1] == " ":
        str1 = str1[:-1]
    return str1
