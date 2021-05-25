#!/bin/bash

if [ -d "math" ]
then
	rm -rf math
fi
if [ -d "text" ]
then
	rm -rf text
fi

for (( i=1; i<4; i++ ))
do
	> math_$i
	> text_$i
done

for file in ./*
do
        folder_1=${file##*/}
        folder_2=${folder_1%.*}
        folder_3=${folder_2%_*}
        if [ $folder_3 = "math" ] || [ $folder_3 = "text" ] 
	then
		if [ -d $folder_3 ] && [ -f $file ]
        	then
        	        mv "$file" "./$folder_3"
        	else
        	        mkdir $folder_3
        	        mv "$file" "./$folder_3"
        	fi
	fi
done
echo 'ls directory math'$'\n'
ls math
echo $'\n''ls directory text'$'\n'
ls text
