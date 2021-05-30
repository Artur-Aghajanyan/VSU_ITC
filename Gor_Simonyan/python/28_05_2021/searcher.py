import os
import re
import sys


def check():
    global file_dir, file_dir_name, text, file_path, include, exclude
    length = len(words)
    i = 0
    try:
        while i < length:
            if words[i].startswith("-"):
                if words[i] == "-f" or words[i] == "--file":
                    file_dir = "-f"
                    file_dir_name = words[i+1]
                elif words[i] == "-d" or words[i] == "--directory":
                    file_dir = "-d"
                    file_dir_name = words[i+1]
                elif words[i] == "-s" or words[i] == "--search":
                    text = words[i+1]
                elif words[i] == "-p" or words[i] == "--path":
                    file_path = words[i+1]
                elif words[i] == "-i" or words[i] == "--include":
                    if words[i+1] != "[":
                        include = words[i+1].split()
                    else:
                        words.pop(i + 1)
                        length -= 1
                        while i+1 < length:
                            if words[i+1] == "]":
                                break
                            include.append(words[i+1])
                            words.pop(i+1)
                            length -= 1
                elif words[i] == "-e" or words[i] == "--exclude":
                    if words[i + 1] != "<":
                        exclude = words[i + 1].split()
                    else:
                        words.pop(i + 1)
                        length -= 1
                        while i + 1 < length:
                            if words[i + 1] == ">":
                                break
                            exclude.append(words[i + 1])
                            words.pop(i + 1)
                            length -= 1
                else:
                    print("Invalid flag!", words[i])
                    exit()
                words.pop(i + 1)
                words.pop(i)
                length -= 2
            else:
                i += 1
    except:
        print("Invalid flag!")
        exit()
    if len(words) > 1 or (len(words) == 1 and file_dir_name):
        print("Invalid words!", words)
        exit()
    elif not file_dir_name and len(words) == 1:
        file_dir_name = words[0]
    return True


def file_open(file_path):
    if os.path.exists(file_path) is False:
        print("Invalid path!")
        exit()
    global file_dir, text, exclude, include, file_dir_name, file_found, text_found
    try:
        for files in os.listdir(file_path):
            t = True
            for i in exclude:
                if files == i:
                    t = False
                    break
            for i in include:
                if include and files == i:
                    t = True
                    break
                t = False
            if t:
                if os.path.isfile(file_path+files):
                    if file_dir_name and files == file_dir_name and file_dir == "-f":
                        print("File ", file_dir_name, " founded.")
                        print("path:", file_path+files, "\n")
                        file_found = True
                    if text:
                        with open(file_path + files, 'r') as file:
                            line_number = 1
                            printed = True
                            for line in file:
                                m = re.search(text, line)
                                if m is not None:
                                    if printed:
                                        print("Words founded in:")
                                        print("file: ", file_path + files)
                                        printed = False
                                    print("line: ", line_number, ": ", line)
                                    text_found = True
                                line_number += 1
                if os.path.isdir(file_path+files):
                    if file_dir_name and files == file_dir_name and file_dir == "-d":
                        print("""Directory founded.
        path:""", file_path + files, "\n")
                    file_open(file_path+files+"/")
    except:
        pass


file_dir = "-f"
file_dir_name = ""
file_found = False
text = ""
text_found = False
file_path = "/"
include = []
exclude = []
words = sys.argv
words.pop(0)
if len(words) < 1:
    print("Write arguments!")
    exit()

check()
file_open(file_path)

if file_dir_name and file_found is False:
    print("File ", file_dir_name, " not founded!")
if text and text_found is False:
    print("Word ", text, " not founded!")

