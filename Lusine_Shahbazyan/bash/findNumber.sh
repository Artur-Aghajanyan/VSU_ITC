#!/bin/bash

echo "Script generates a random number between 1 & 20."
echo "You have 3 chances to find what number it is. Lets start"

randomNumber=$(( RANDOM % 20 + 1))
notFound=true
echo "number is"
for i in {1..3}
do
    read number
    if [ $number == $randomNumber ]
    then
        echo "Yes. You have found the number.Congratulations."
        notFound=false
        break
    elif [ $number -gt $randomNumber ]
    then
        echo "Your number  is greater than random number."
        continue
    else 
        echo "Your number is less than random number."
        continue
    fi
done
if $notFound
then
    echo "Sorry, you can't find the number. Number is"
    echo $randomNumber
fi
  

