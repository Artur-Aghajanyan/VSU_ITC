#!/bin/bash

echo Armen xndzor 5000 10/02/2021$'\n'Mane elak 4900 11/02/2021$'\n'Narek dexc 6500 09/02/2021$'\n'Borik gilas 3200 05/02/2021 > list.txt

echo General file$'\n'
cat list.txt

if [[ -f sorted_list.txt ]]
then
	rm sorted_list.txt
fi

awk '{print $1,$3}' list.txt >> sorted_list.txt

echo $'\n'Sort_File before sorting$'\n'
cat sorted_list.txt

line_count=`wc -l sorted_list.txt | awk '{ print $1 }'`

for (( j=1; j<=$line_count; j++ ))
do
	for (( i=1; i<=$(($line_count-1)); i++ ))
	do
		word1=`awk 'NR=='$i'{print $2}' sorted_list.txt`
		word2=`awk 'NR=='$(($i+1))'{print $2}' sorted_list.txt`
		if [ $(($word1)) -gt $(($word2)) ]
	        then
			line1=`awk "NR==$(($i)){print;exit}" sorted_list.txt`
			line2=`awk "NR==$(($i+1)){print;exit}" sorted_list.txt`
			sed -i "$(($i))s/.*/$line2/" sorted_list.txt
			sed -i "$(($i+1))s/.*/$line1/" sorted_list.txt
	        fi
	done
done

echo $'\n'Sort_File After sorting$'\n'
cat sorted_list.txt
