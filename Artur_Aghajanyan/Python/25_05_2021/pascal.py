#from __future__ import print_function

n = input("Row: ")

def printPascal(n):
    for line in range(1, n + 1):
        el = 1
        for i in range(1, line + 1):
            print(el, end = " ");
            el = int(el * (line - i) / i);
        print("")

printPascal(int(n))
