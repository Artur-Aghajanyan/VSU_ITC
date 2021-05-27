def checker(word, lines):
    for i in range(len(counter[0])):
        if counter[0][i] == word:
            counter[1][i] += 1
            return True
    if lines != 0:
        counter[0].append(word)
        counter[1].append(1)


def line_checker(word):
    for i in line:
        if i == word:
            return False
    line.append(word)
    return True


def if_count(count):
    for i in counter[1]:
        if i == count:
            return True
    return False


def print_count(count):
    for i in range(len(counter[0])):
        if counter[1][i] >= count:
            print(counter[0][i], ":", counter[1][i])


def check(count):
    for i in range(len(arr)):
        global line
        line = []
        for j in range(len(arr[i].split())):
            words = arr[i].split()[j]
            if (words[0].isupper() and words[1:].islower()) or words.isupper():
                if line_checker(words.upper()):
                    checker(words.upper(), j)
    if if_count(count):
        print_count(count)
    elif not counter[0]:
        print("No Result")
    else:
        for i in range(len(counter[0])):
            print(counter[0][i], ":", counter[1][i])


arr = []
counter = [[], []]
line = []
print("Input your text(for end push ENTER and write end):")
while True:
    arr.append(input())
    if arr[-1] == "end":
        break
while True:
    try:
        a = int(input("Input count - "))
    except(ValueError):
        print("Pls, write number!")
        continue
    check(a)
    break

