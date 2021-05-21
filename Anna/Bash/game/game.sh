#!/bin/bash

attempts=3
number=$[( $RANDOM % 10 ) +1]

for (( i=1 ; i <= $attempts ; i++ )) ; do

    read -p "Enter number between 1 and 10  " value

    echo "You enterd $value"

    if [ "$number" -eq "$value" ]; then
        echo "You guessed the number!"
        break
    fi

    if [ $i -ge $attempts ] ; then
        echo "You only have  $attempts attempts!"
        break

    elif [ "$number" -gt "$value" ]; then
        echo "It should be greater than the inputting number!"

    elif [ "$number" -lt "$value" ]; then
        echo "It should be less than the inputting number!"
    fi

done

