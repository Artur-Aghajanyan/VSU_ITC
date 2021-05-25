#!/bin/bash

echo Hello World! > text1.txt
echo 11111 22222! > text2.txt
echo Before swap text1.txt:$'\n'
cat text1.txt
echo $'\n'Before swap text2.txt.$'\n'
cat text2.txt
text=$(<text2.txt)
cat text1.txt > text2.txt
echo $text > text1.txt
echo $'\n'After swap text1.txt$'\n'
cat text1.txt
echo $'\n'After swap text2.txt$'\n'
cat text2.txt

