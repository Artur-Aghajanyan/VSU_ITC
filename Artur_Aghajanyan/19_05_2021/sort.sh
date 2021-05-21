#!/bin/bash
file="data"
counter=1
cp $file temp
if [ $counter -eq 0 ]
then
	echo "Hello"
fi
length=$(wc -l data | awk '{ print $1 }')
while read line
    do
		counter=$((counter+1))
		#echo $line
		max=${line##* }
		#echo $max
		for ((j = $counter; j < $length; ++j))
		do
			nextValue=$(sed -n "${j}p" < $file)
			value=${nextValue##* }

			if [ $value -ge $max ]
			then
				
			fi
		done
		
done < $file

