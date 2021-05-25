#!/bin/bash
RESULT=`shuf -i 1-20 -n 1`
echo "Enter number from 1 to 20"
for i in {1..3}
do
    read a1
if [ $a1 -lt 1 -o $a1 -gt 20 ]
then
    echo "Enter number from 1 to 20"
elif [ $a1 -eq $RESULT ]
then 
    echo "Correct"
 exit
elif [ $a1 -gt $RESULT ]
then
    echo "It should be less than the inputting number"
    continue
  else 
    echo "It should be greater than the inputting number"
fi
done
echo "You weren't able to find correct number"
