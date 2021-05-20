#!/bin/bash
r=$((( RANDOM % 20 )  + 1 ))
x=0
echo -n "Enter some number in 1-20 range > "
while [ $x -lt 3 ]
do 
read number
((x++))
if [ $number -lt $r ]
then
	echo "It should be greater than the inputting number"
elif [ $number -gt $r ]
then
	echo "It should be less than the inputting number"
else
	echo "You WIN, $number is right answer "
	break
fi
done
echo $r
