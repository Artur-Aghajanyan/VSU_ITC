#!/bin/bash

declare -A array
step=0
Green="\e[32m"
Magenta="\e[35m"
Cyan="\e[36m"
Red="\e[91m"

restart(){
    for ((i=0; i<3; ++i))
    do
        for ((j=0; j<=3; ++j))
        do
            array[$i,$j]='.'
        done
    done
    step=0
    read -p " First player name :  " player1
    read -p " Second player name :  " player2
    echo -e "${Magenta} $player1--0 ${Magenta}"
    echo -e "${Green} $player2--x ${Green}"
    symbol=0
    player=$player1
    gameStatus=1
    echo "=============="
    echo -e "${Cyan} Game started ${Cyan}"
    echo ""
}

print(){
    echo " r\c 0   1   2"
    echo ""
    echo " 0   ${array[0,0]} | ${array[0,1]} | ${array[0,2]}"
    echo "    ___________"
    echo " 1   ${array[1,0]} | ${array[1,1]} | ${array[1,2]}"
    echo "    ___________"
    echo " 2   ${array[2,0]} | ${array[2,1]} | ${array[2,2]}"
}

set(){
    i=$(( $1 ))
    j=$(( $2 ))
    if [ ${array[$i,$j]} == "." ];
    then
        array[$i,$j]=$3
        step=$(($step + 1))
        if [ $player == $player1 ]
        then
            player=$player2
        else
            player=$player1
        fi
    else
        echo -e "${Cyan} You can't place there! ${Cyan}"
    fi
}

checkCol(){
    if [ ${array[0,$1]} != "." ] && [ ${array[0,$1]} == ${array[1,$1]} ] && [ ${array[0,$1]} == ${array[2,$1]} ];
    then
        gameStatus=0
    fi
}

checkRow(){
    if [ ${array[$1,0]} != "." ] && [ ${array[$1,0]} == ${array[$1,1]} ] && [ ${array[$1,0]} == ${array[$1,2]} ];
    then
        gameStatus=0
    fi
}

checkDiagonal1(){
    if [ ${array[0,0]} != "." ] && [ ${array[0,0]} == ${array[1,1]} ] && [ ${array[0,0]} == ${array[2,2]} ];
    then
        gameStatus=0
    fi
}

checkDiagonal2(){
    if [ ${array[0,2]} != "." ] && [ ${array[0,2]} == ${array[1,1]} ] && [ ${array[0,2]} == ${array[2,0]} ];
    then
        gameStatus=0
    fi
}

checkGame(){
    checkRow 0
    checkRow 1
    checkRow 2
    checkCol 0
    checkCol 1
    checkCol 2
    checkDiagonal1
    checkDiagonal2
}

playAgain(){
    echo -e "${Green} Do you want play again :  yes/no ${Green}"
    read  input
    if [ $input == "yes" ];
    then
        restart
    else
        exit
    fi
}

restart
print 
while [ 1 == 1 ]; 
do
    echo ""
    if [ $player == $player1 ];
    then
        symbol="0"
    else
        symbol="x"
    fi
    echo ""
    echo -e "${Cyan} $player : ($symbol)  enter row  col ${Cyan}"
    while [ 1 == 1 ]; 
    do
        read  i j
        echo "====================="
        if [ $i -eq 0 ] || [ $i -eq 1 ] || [ $i -eq 2 ]
        then
            if [ $j -eq 0 ] || [ $j -eq 1 ] || [ $j -eq 2 ]
            then
                set $i $j $symbol
                break
            else
                echo -e "${Green} Wrong value, try again. ${Green}"
            fi
        else
            echo -e "${Green} Wrong value, try again.${Green}"
        fi
    done
    print

    checkGame
    if [ $gameStatus != 1 ]
    then
        echo -e "${Red} Gameover ${Red}"
        echo -e "${Red} Player $player ($symbol) win!! ${Red}"
        echo ""
        playAgain
    else
        if [ $step == 9 ]
        then
            echo ""
            echo -e "${Red} Game over in a draw !! ${Red}"
            playAgain
        fi
    fi
done




