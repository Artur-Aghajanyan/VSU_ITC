n = input("n =  ")

def printPascalLines(n):
    PascallArray = [[0 for x in range(n)] for y in range(n)]
    for line in range (n):
        for i in range (line + 1):
            if(i == 0 or i == line):
                PascallArray[line][i] = 1
                print(PascallArray[line][i], end = " ")
            else:
                PascallArray[line][i] = (PascallArray[line - 1][i - 1] + PascallArray[line - 1][i])
                print(PascallArray[line][i], end = " ")            
        print("\n", end = "")
 
printPascalLines(int(n))
