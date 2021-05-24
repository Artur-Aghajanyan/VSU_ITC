#!/bin/bash

read -p "Write 1 number - " num1
read -p "Write 2 number - " num2
if [ -z $num1 ] || [ -z $num2 ]
then
    echo Error
    exit
fi
if ! [[ $num1 =~ ^[1-9]+$ ]] || ! [[ $num2 =~ ^[1-9]+$ ]]
then
    echo $num1$num2
else
    read -p "Write operator - " oper
    case $oper in
	'+')
	    echo $num1 + $num2 | bc
	    ;;
	'-')
	    echo $num1 - $num2 | bc
	    ;;
	'*')
	    echo "$num1 * $num2" | bc
	    ;;
	'/')
	    if [ $num2 -eq 0 ]
	    then
		echo Error / 0
	    else
		echo "scale=1; $num1 / $num2" | bc
	    fi
	    ;;
	*)
	    echo Error
	    ;;
    esac
    echo $sum
fi
