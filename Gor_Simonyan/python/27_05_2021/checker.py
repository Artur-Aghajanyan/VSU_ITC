def checker(word, lines):
    for i in range(len(counter[0])):
        if counter[0][i] == word:
            counter[1][i] += 1
            return True
    if lines != 0:
        counter[0].append(word)
        counter[1].append(1)
        return True
    return False


def line_checker(word):
    for i in line:
        if i == word:
            return False
    line.append(word)
    return True


def print_count(count):
    for i in range(count):
        print(counter[0][i], ":", counter[1][i])


def sort_list():
    for i in counter[0]:
        for j in range(len(counter[0])-1):
            if counter[1][j] < counter[1][j+1]:
                counter[0][j], counter[0][j+1] = counter[0][j+1], counter[0][j]
                counter[1][j], counter[1][j + 1] = counter[1][j + 1], counter[1][j]


def check(count):
    for i in range(len(arr)):
        global line
        line = []
        for j in range(len(arr[i].split())):
            words = arr[i].split()[j]
            if ((words[0].isupper() and words[1:].islower()) or words.isupper()) and line_checker(words.upper()) and \
                    checker(words.upper(), j) is False:
                line.pop()

    sort_list()
    if not counter[0]:
        print("No Result!")
    elif count <= len(counter[0]):
        print_count(count)
    else:
        print_count(len(counter[0]))


arr = []
counter = [[], []]
line = []
print("Input your text:")
while True:
    arr.append(input())
    if arr[-1] == "end":
        break
while True:
    try:
        a = int(input("Input count - "))
    except ValueError:
        print("Pls, write number!")
        continue
    check(a)
    break
