#!/bin/bash

#mkdir newdir
#find . -name '*.cpp' | cpio -o < newdir > archive

cp 1.txt temp
cp 2.txt 1.txt
cp temp 2.txt
rm temp
