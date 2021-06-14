def counter(lst,Dict):
    if len(lst) == 0:
        lst[str(lst)] = 1
        return 0

    for key in Dict:
        if key.upper() == lst.upper(): 
            Dict[key] += 1
            return 0
    Dict[str(lst)] = 1


def sorting(Dict):
    List=list(Dict.items())
    l=len(List)
    for i in range(l-1):
        for j in range(i+1,l):
            if List[i][1] < List[j][1]:
                temp = List[i]
                List[i] = List[j]
                List[j] = temp
        sortDict = dict(List)
        return sortDict
 
def printDict(dict1,n):
    if n > len(dict1) or n < 0:
        print("Your input great in list length or small of 0")
        return 0

    for k, v in dict1.items():
        if n == 0:
            break
        print(k, v)
        n -= 1

   
