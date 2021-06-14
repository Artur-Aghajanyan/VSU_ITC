def word_count(str):
    '''
        word_count function has 1 string type argument. Function finds words whose letters are uppercase or whose only first letter starts with uppercase and returns them as a list.
    '''
    
    counts = dict()
    words = str.split()
    num = 0
    
    for word in words:
        a = list(word)
        
        if a[0].isupper():
            for i in range(1, len(a)):
                if a[i].isupper():
                    num += 1
                    
            if num == len(a) - 1:
                if word in counts:
                    counts[word] += 1
                else:
                    counts[word] = 1
                    
            elif num == 0:
                word = a[0]
                
                for i in range(1, len(a)):
                    a[i] = a[i].upper()
                    word += a[i]
                    
                if word in counts:
                    counts[word] += 1
                else:
                    counts[word] = 1
                    
            num = 0

    return counts.keys()
  
print("To finish program enter ctrl+c.")
print("To end the input of the text enter '~' simbole.")
print("Enter the text.")
list2 = []
list3 = []
list4 = []
list5 = []
list6 = []
list7 = []
list8 = []
count = 0
number = 0
one = 0

while True:
    list2.append(input())
    count += 1
    if list2[-1] == "~":
        break

while True:
    try:
        a = int(input("Enter the count: "))
        one += 1
        if a < 0:
            print("Entered wrong value. Plesase enter positive number.")
            continue
    except(ValueError):
        print("Entered wrong value. Plesase enter positive number.")
        continue
    

    if one == 1:
        for i in range(0, count-1):
            z = list(word_count(list2[i]))
            
            for j in range(0,len(z)):
                list3.append(z[j])
                number += 1

        for i in range(0, number-1):
            for j in range(0, number-i-1):
                if list3[j] > list3[j+1]:
                    list3[j], list3[j+1] = list3[j+1], list3[j]

        h = 0

        for i in range (0, number):
            if i == number - 1:
                if list3[i] == list3[i-1]:
                    list4.append(list4[len(list4)-1] + 1)
                    list5.append(list3[i])
                else:
                    list4.append(1)
                    list5.append(list3[i])
            elif list3[i] == list3[i+1]:
                h += 1
            else:
                list4.append(h+1)
                list5.append(list3[i])
                h = 0
        list7.extend(list4)
        list8.extend(list5)
        
    i = 0
    j = 0
    q = len(list4)

    while j < a:
        i = 0
        while i < q:
            if list4[i] == max(list4):
                list6.append(list5[i])
                list4.pop(i)
                list5.pop(i)
                break
            i += 1
        j += 1
        
    print(*list6)
    list6 = []
    list4 = []
    list5 = []
    list4.extend(list7)
    list5.extend(list8)
