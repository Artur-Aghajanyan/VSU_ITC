#!/bin/bash

echo "This script calculate two variables"
read -p "Enter first variable : " var1
read -p "Enter second variable : " var2
read -p "Enter kind of operation :" opr

flag=0
checkValue(){
    check1=`echo "$var1" | grep -E ^\-?[0-9]*\.?[0-9]+$`
    check2=`echo "$var2" | grep -E ^\-?[0-9]*\.?[0-9]+$`

    if [ "$check1" == '' ] || [ "$check2" == '' ];
    then
        flag=1
    fi
}

checkValue
                  
sumFunc(){
    if [ $flag -eq 1 ]
    then
        echo $var1$var2
    else
        sum=$(($var1 + $var2)) 
        echo $sum
    fi 
}

mulFunc(){
    if [ $flag -eq 1 ]
    then
        echo "Wrong entering value"
    else
        mul=$(($var1 * $var2))
        echo $mul
    fi
}

diffFunc(){
    if [ $flag -eq 1 ]
    then
        echo "Wrong entering value"
    else
        diff=$(($var1 - $var2))
        echo $diff
    fi
}

dividFunc(){
    if [ $flag -eq 1 ]
    then
        echo "Wrong entering value"
    else
        div=$(($var1 / $var2))
        echo $div
    fi
}

case $opr in
    "*")
        mulFunc 
        ;;
    "+")
        sumFunc
        ;;
    "-")
        diffFunc
        ;;
    "/")
        if [ $var2 -eq 0 ]
        then
            echo "Impossible  divide by 0"
            exit
        fi
        dividFunc
        ;;
    *)
        echo "It is wrong value for operation"
esac








