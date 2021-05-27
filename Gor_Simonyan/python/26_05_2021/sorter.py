def let_sort(index, word_index):
    word1 = arr[index].split()[word_index]
    word2 = arr[index + 1].split()[word_index]
    for i in range(len(word1)):
        if arr[index].split()[word_index][i].isalpha():
            if i == 1 and len(word1) > len(word2):
                swap(index)
                return True
            if arr[index].split()[word_index][i] > arr[index+1].split()[word_index][i]:
                swap(index)
                return True
            if arr[index].split()[word_index][i] < arr[index+1].split()[word_index][i]:
                return True
    return False


def num_sort(index, word_index):
    word1 = arr[index].split()[word_index]
    word2 = arr[index+1].split()[word_index]
    for i in range(len(word1)):
        if arr[index].split()[word_index][i].isnumeric():
            if i == 1 and len(word1) > len(word2):
                swap(index)
                return True
            if arr[index].split()[word_index][i] > arr[index+1].split()[word_index][i]:
                swap(index)
                return True
            if arr[index].split()[word_index][i] < arr[index+1].split()[word_index][i]:
                return True
    return False


def is_num(index):
    for i in range(1, 3):
        if arr[index].split()[i].isnumeric() is False:
            return False
    return True


def is_let(index):
    for i in range(1, 3):
        if arr[index].split()[i].isalpha() is False:
            return False
    return True


def check():
    for j in range(0, len(arr)):
        for i in range(0, len(arr) - 1):
            if is_num(i):
                if is_num(i+1):
                    if num_sort(i, 0) is False:
                        if let_sort(i, 0) is False:
                            if num_sort(i, 1) is False:
                                num_sort(i, 2)
                else:
                    swap(i)
            else:
                if is_num(i+1):
                    continue
                else:
                    if let_sort(i, 0) is False:
                        if num_sort(i, 0) is False:
                            if let_sort(i, 1) is False:
                                let_sort(i, 2)
    for i in arr:
        print(i)


def swap(index):
    arr[index], arr[index + 1] = arr[index + 1], arr[index]


arr = []
print("Keys examples: w32 34 5634, w12 asdfaf da")
print("For sorting write sort")
while True:
    arr.append(input("Input keys - "))
    if arr[-1] == "sort":
        arr.pop()
        break
    if len(arr[-1].split()) != 3 or len(arr[-1].split()[0]) != 3 or arr[-1].split()[0][0].isalpha() is False or \
            arr[-1].split()[0][1:2].isnumeric() is False or (is_num(-1) is False and is_let(-1) is False):
        print("Invalid keys!")
        arr.pop()
        continue
print('\n')
check()

