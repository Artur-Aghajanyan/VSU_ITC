#!/bin/bash
echo "Let's play a game."
echo "You have 3 chances."
echo "Pick a number between 0 and 20: "
number=$(( RANDOM % 20 ))
res=0
for var in {1..3}
do
	
	read a
	if [ $number -eq $a ]
   	then
		$res=1
		echo AMAZING, your answer is correct
		break
	elif [ $number -lt $a ]
   	then
		echo It should be less than the inputting number
	elif [ $number -gt $a ]
   	then
		echo It should be greater than the inputting number
	fi
done

if [ $res -eq 0 ]
then
	echo -n "You cant found number, Number is: "
	echo $number
fi
