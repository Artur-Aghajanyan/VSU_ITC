#!/bin/bash

number=`echo $((1 + $RANDOM % 20))`
for (( i=1; i<4; i++ ))
do
	echo '-n' 'Write the number(1 - 20) - ' 
	read 
	if [ -z ${REPLY} ] || [ ${REPLY} -gt 20 ] || [ ${REPLY} -lt 0 ]
	then
		echo Plz enter number in space 1-20
		i=$(($i-1))
	elif [ ${REPLY} -eq $number ]
        then
                echo Yes!You gess!
                exit
	elif [ ${REPLY} -gt $number ] && [ $i -ne 3 ]
	then
		echo It should be less than the inputting number
	elif [ ${REPLY} -lt $number ] && [ $i -ne 3 ]
	then	
		echo It should be greater than the inputting number
	fi
done	
echo "Sorry, you did not guess!The number is $number"
