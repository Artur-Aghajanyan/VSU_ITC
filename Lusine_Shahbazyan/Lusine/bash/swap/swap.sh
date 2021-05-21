#!/bin/bash

#mkdir newdir
#find . -name '*.cpp' | cpio -o < newdir > archive

echo "Content of 1.txt file before swapping is"
cat 1.txt

echo "Content of 2.txt file before swapping is"
cat 2.txt

cp 1.txt temp
cp 2.txt 1.txt
cp temp 2.txt
rm temp

echo "Content of 1.txt file after swapping is"
cat 1.txt

echo "Content of 2.txt file after swapping is"
cat 2.txt

