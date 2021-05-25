#!/bin/bash

turn=0
k=false
moves=( '.' '.' '.' '.' '.' '.' '.' '.' '.' )

print_board () {
    echo " ${moves[0]} | ${moves[1]} | ${moves[2]} "
    echo "-----------"
    echo " ${moves[3]} | ${moves[4]} | ${moves[5]} "
    echo "-----------"
    echo " ${moves[6]} | ${moves[7]} | ${moves[8]} "
}

player_1='X'
player_2='O'

pick_player () {
    if [ $(($turn % 2)) -eq 0 ]
    then
        echo -n "Player 1 pick a square: "
        play=$player_1
        turn=$((turn+1))
    else
        echo -n "Player 2 pick a squire: "
        play=$player_2
        turn=$((turn+1))
    fi
}

val=0

is_picked () {
    if [ ${moves[$((a-1))]}  == 'X' ] || [ ${moves[$((a-1))]} == 'O' ]
    then
        echo "This value is already picked. Try again."
        turn=$((turn-1))
        val=$((val+1))
    fi
}

pick_value () {
    pick_player
    read a
    case $a in
    '1')
        is_picked
        if [ $val == 0 ]
        then
            moves[0]=$play
        fi
        val=0
        ;;
    '2')
        is_picked
        if [ $val == 0 ]
        then
            moves[1]=$play
        fi
        val=0
        ;;
    '3')
        is_picked
        if [ $val == 0 ]
        then
            moves[2]=$play
        fi
        val=0
        ;;
    '4')
        is_picked
        if [ $val == 0 ]
        then
            moves[3]=$play
        fi
        val=0
        ;;
    '5')
        is_picked
        if [ $val == 0 ]
        then
            moves[4]=$play
            fi
        val=0
        ;;
    '6')
        is_picked
        if [ $val == 0 ]
        then
            moves[5]=$play
        fi
        val=0
        ;;
    '7')
        is_picked
        if [ $val == 0 ]
        then
            moves[6]=$play
        fi
        val=0
        ;;
    '8')
        is_picked
        if [ $val == 0 ]
        then
            moves[7]=$play
        fi
        val=0
        ;;
    '9')
        is_picked
        if [ $val == 0 ]
        then
            moves[8]=$play
        fi
        val=0
        ;;
    *)
        echo "Entered wrong value. It should be a value in 1-9 range."
        turn=$((turn-1))
        pick_value
        ;;
esac
}

draw=0

check_winner () {
    if [ ${moves[$1]} != '.' ]
    then
        if [ ${moves[$1]} == ${moves[$2]} ] && [ ${moves[$2]} == ${moves[$3]} ]
        then
            if [ $play == 'X' ]
            then
                echo "Player 1 win the game!"
                k=true
                main
            else
                echo "Player 2 win the game!"
                k=true
                main
            fi
        else
            draw=$((draw+1))
            k=false
        fi
    fi
}

check () {
    draw=0
    check_winner 0 1 2
    check_winner 3 4 5
    check_winner 6 7 8
    check_winner 0 3 6
    check_winner 1 4 7
    check_winner 2 5 8
    check_winner 0 4 8
    check_winner 2 4 6
}

main () {
    for (( ; ; ))
    do
        if [ $k == true ]
        then
            echo "Try again"
            turn=0
            k=false
            moves=( '.' '.' '.' '.' '.' '.' '.' '.' '.' )
            main
        else
            if [ $draw == 8 ]
            then
                echo "The game ended in a draw."
                echo "Try again"
                turn=0
                k=false
                moves=( '.' '.' '.' '.' '.' '.' '.' '.' '.' )
                draw=0
                main
                break 1
            else
                pick_value
                print_board
                check
            fi
        fi
    done
}
main
