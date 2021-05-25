#!/bin/bash

declare -a Arr
colors=("\033[47;" "\033[40;")

function Print_Board
{
    local i1=0
    local i2=1
    local count1=1
    local count2=1
    local index=1
    for (( q=1; q<10; q++ ))
    do
	if [ $count1 -eq 4 ]
	then 
	    eval $(echo i1=$i2\;i2=$i1)
	    count1=1
	fi
	for (( j=1; j<16; j++ ))
	do
	    if [ $count2 -eq 6 ]
	    then
		eval $(echo i1=$i2\;i2=$i1)
		count2=1
	    fi
	    f="32m "
	    if [ $count1 -eq 2 ] && [ $count2 -eq 3 ]
	    then
		f=${Arr[$index]}
		index=$(( $index+1 ))
	    fi
	    printf "${colors[$i1]}$f\033[0m"
	    count2=$(( $count2+1 ))
	done
	echo
	eval $(echo i1=$i2\;i2=$i1)
	count1=$(( $count1+1 ))
    done
}

function Cell
{
    if [[ "$cell" =~ ^[1-9]+$ ]] && [ $cell -ge 1 ] && [ $cell -le 9 ]
    then
	if [[ ${Arr[$cell]} != 31mX ]] && [[ ${Arr[$cell]} != 31mO ]]
	then
	    Arr[$cell]=$turn
	    return 0
	fi
	return 1
    fi
    return 1
}

function Check
{
    if ([ ${Arr[1]} = ${Arr[2]} ] && [ ${Arr[2]} = ${Arr[3]} ]) || ([ ${Arr[4]} = ${Arr[5]} ] && [ ${Arr[5]} = ${Arr[6]} ]) || ([ ${Arr[7]} = ${Arr[8]} ] && [ ${Arr[8]} = ${Arr[9]} ]) || ([ ${Arr[1]} = ${Arr[4]} ] && [ ${Arr[4]} = ${Arr[7]} ]) || ([ ${Arr[2]} = ${Arr[5]} ] && [ ${Arr[5]} = ${Arr[8]} ]) || ([ ${Arr[3]} = ${Arr[6]} ] && [ ${Arr[6]} = ${Arr[9]} ]) || ([ ${Arr[1]} = ${Arr[5]} ] && [ ${Arr[5]} = ${Arr[9]} ]) || ([ ${Arr[3]} = ${Arr[5]} ] && [ ${Arr[5]} = ${Arr[7]} ])
    then
	Print_Board
	printf $'\t'"\033[42;$turn win!\033[0m"
	echo
	i=11
    fi
}

function Check_cell
{
    if [ ${Arr[$1]} != "31mO" ] && [ ${Arr[$1]} != "31mX" ] && [ ${Arr[$2]} = ${Arr[$3]} ]
    then
	t=$1
	return $t
    fi
}

function Bot
{
    t=0
    Check_cell 3 1 2
    Check_cell 1 3 2
    Check_cell 2 3 1
    Check_cell 6 4 5
    Check_cell 4 6 5
    Check_cell 5 6 4
    Check_cell 9 7 8
    Check_cell 7 8 9
    Check_cell 8 7 9
    Check_cell 7 1 4
    Check_cell 4 1 7
    Check_cell 1 4 7
    Check_cell 8 2 5
    Check_cell 5 2 8
    Check_cell 2 5 8
    Check_cell 9 3 6
    Check_cell 6 3 9
    Check_cell 3 6 9
    Check_cell 9 1 5
    Check_cell 5 1 9
    Check_cell 1 5 9
    Check_cell 7 3 5
    Check_cell 5 3 7
    Check_cell 3 5 7
    if [ $t -ne 0 ]
    then 
	return $t
    fi
}

p=1
while [ $p -eq 1 ]
do
    for ((i=1;i<=9;i++))
    do
	Arr[$i]="32m$i"
    done
    while :
    do
	read -p 'Write "bot" for playing with Bot and "player" for 2 players - ' play
	if [ -z $play ]
	then
	    echo Write!
	elif [ $play = "bot" ] || [ $play = "player" ]
	then 
	    break
	else
	    echo Invalid word!
	fi
    done
    if [ $play = "bot" ]
    then
	while :
	do
	    read -p "You want to play with X or O - " XO
	    if [ -z $XO ]
	    then
	        echo write!
	    elif [ $XO = X ] || [ $XO = O ]
	    then
		break
	    fi
	    echo Plz write X or O!
	done
	for (( i=1; i<10; i++ ))
	do	
	    Print_Board
	    if [ $(( $i%2 )) -eq 0 ]
	    then
		echo '      O turn'
		turn="31mO"
	    else
		echo '      X turn'
		turn="31mX"
	    fi
	    if ([ $turn = "31mX" ] && [ $XO = X ]) || ([ $turn = "31mO" ] && [ $XO = O ])
	    then
		read -p 'Select cell - ' cell
		Cell
		if [ $? -eq 1 ]
		then
		    echo Cell is not empty or invalid cell
		    i=$(( $i-1 ))
		    continue
		fi
		Check
	    else
		Bot
		if [ $t -ne 0 ]
		then
		    cell=$t
		    Cell
		else
		    while :
		    do
			cell=$((($RANDOM%9)+1))
			Cell
			if [ $? -eq 0 ]
			then
			    break
			fi
		    done
		fi
		Check
	    fi

	done
	if [ $i -eq 10 ]
	then
	    Print_Board
	    echo Draw!
	fi
    elif [ $play = "player" ]
    then
	for (( i=1; i<10; i++ ))
	do
	    Print_Board 
	    if [ $(( $i%2 )) -eq 0 ]
	    then
		echo '      O turn'
		turn="31mO"
	    else
		echo '      X turn'
		turn="31mX"
	    fi
	    read -p 'Select cell - ' cell
	    Cell
	    if [ $? -eq 1 ] 
	    then 
		i=$(( $i-1 ))
		continue
	    fi
	    Check

	done
	if [ $i -eq 10 ]
	then
	    Print_Board
	    echo Draw!
	fi
    fi
    while :
    do
	read -p 'Would you want start newgame("yes" or "no")? - ' newgame
	if [ -z $newgame ]
	then
		echo write!
	elif [ $newgame = "no" ] 
	then
	    exit
	elif [ $newgame = "yes" ]
	then
	    break
	else
	    echo Plz,write yes or no
	fi
    done
done
