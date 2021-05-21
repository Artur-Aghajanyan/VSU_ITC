#!/bin/bash

echo "Content of text.txt file"
cat text.txt
echo "This script shows only 2th and 3th column of file and sort the list by price "
rm -f newtext.txt
awk '{ print $2, $3 }' text.txt >> newtext.txt
> sortedList.txt

lineCount=`wc -l newtext.txt | awk '{ print $1 }'`
for (( i=1; i<=$lineCount; ++i ))
do
    line=$(sed -n '1p' < newtext.txt)
    min=${line#* }
    count=1
    for (( j=2; j<=$lineCount; ++j))
    do
        line1=$(sed -n "${j}p" < newtext.txt)
        min1=${line1#* }
        if [ $min -gt $min1 ]
        then
             min=$min1
             count=$j
         fi
    done
    sed -n "${count}p" newtext.txt >> sortedList.txt
    sed -i "${count}d" newtext.txt
done
rm newtext.txt
cat sortedList.txt
rm sortedList.txt
