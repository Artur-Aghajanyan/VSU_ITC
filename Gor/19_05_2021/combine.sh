#!/bin/bash

for (( i=1; i<4; i++ ))
do
	> math_$i
	> test_$i
done

for file in ./*
do
        folder_1=${file##*/}
        folder_2=${folder_1%.*}
        folder_3=${folder_2%_*}
        if [ -d $folder_3 ]
        then
                mv "$file" "./$folder_3"
        else
                mkdir $folder_3
                mv "$file" "./$folder_3"
        fi
done

