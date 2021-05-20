#!/bin.bash
  
rand=$(($RANDOM %20+1))

for x in 1 2 3
do
    echo "Guess the number from 1 to 20: "
    read number

    if (($number > 20))
    then
        echo "Number should be in 1-20 range. Try again."
        read number
    fi

    if (($number == $rand))
    then
        echo "Congretulations! You won the game!"
        break 1

    elif (($number > $rand))
    then
        echo "It should be less than the inputting number."

    else
        echo "It should be greater than the inputting number."
    fi
