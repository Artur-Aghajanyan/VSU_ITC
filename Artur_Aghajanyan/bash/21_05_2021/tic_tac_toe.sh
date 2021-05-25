#!/usr/bin/bash

RED="\e[1;31m"
BLUE="\e[1;34m"
GREEN="\e[1;32m"
YELLOW="\e[1;33m"
WHITE_B="\e[1;30;47m"
END="\e[0m"

player_1="${BLUE}X\e[30;47m"
player_2="${RED}O\e[30;47m"

turn=1
game_on=true

moves=( 1 2 3 4 5 6 7 8 9 )

welcomeMessage() {
  clear
  echo -e "\e[33m"
  echo "============================="
  echo -e "=== ${GREEN}LETS PLAY Tic-Tac-Toe\e[33m ==="
  echo "============================="
  echo -e "\e[0m"
  sleep 2
}

chooseFigure() {
  echo -e "${YELLOW}Do you want to play with a computer or with two players?${END}"
  echo -e "\e[4mCommands${END}: ${GREEN}(C or computer) With a computer   (T or or any other key) Two players${END}"
  read withComputer
  echo -e "\e[33mChoose figure${END}"
  echo -e "\e[4mCommands${END}: ${BLUE}(X)X${END}   ${RED}(O)O${END}"
  res=true
  while $res; do
    read figure
    if [[ $figure == "X" ]] || [[ $figure == "x" ]]
    then
      play=$player_1
      res=flase
    elif [[ $figure == "O" ]] || [[ $figure == "o" ]]
    then
      play=$player_2
      res=flase
    else
      echo -e "${RED}Incorrect Figure!${END}"
    fi
  done
}


printBoard () {
  clear
  echo -e $WHITE_B
  echo -e " ${moves[0]} | ${moves[1]} | ${moves[2]} "
  echo "-----------"
  echo -e " ${moves[3]} | ${moves[4]} | ${moves[5]} "
  echo "-----------"
  echo -e " ${moves[6]} | ${moves[7]} | ${moves[8]} "
  echo -e $END
  echo "============="
}

playerPick(){
  if [[ $(($turn % 2)) == 0 ]]
  then
    echo -en "${YELLOW}PLAYER 2 PICK A SQUARE: ${END}"
  else
    echo -en "${YELLOW}PLAYER 1 PICK A SQUARE: ${END}"
  fi
  if [ $withComputer == "c" ] || [ $withComputer == "C" ] || [ $withComputer == "copmuter" ] || [ $withComputer == "Computer" ]
  then
    if [[ $(($turn % 2)) == 0 ]]
    then
      square=$((1 + $RANDOM % 9))
      while [[ ! $square =~ ^-?[0-9]+$ ]] && [[ ! $space =~ ^[0-9]+$  ]]
      do
        space=${moves[($square -1)]} 
        echo $square
        sq=$(expr $square - 1)
        echo $(expr $sq)
        echo ${move[($square -1)]}
        sleep 1
        square=$((1 + $RANDOM % 9))
      done
    else
      read square
    fi
  else
    read square
  fi

  space=${moves[($square -1)]} 
  if [[ ! $square =~ ^-?[0-9]+$ ]] || [[ ! $space =~ ^[0-9]+$  ]]
  then
    echo "Not a valid square."
    playerPick
  else
    
    moves[($square -1)]=$play
    if [ $play == $player_1 ]
    then 
      play=$player_2
    else
      play=$player_1
    fi
    ((turn=turn+1))
  fi
  space=${moves[($square-1)]} 
}

checkMatch() {
  if  [ ${moves[$1]} == ${moves[$2]} ] && [ ${moves[$2]} == ${moves[$3]} ]; then
    game_on=false
  fi
  
  if [ $game_on == false ]; then
    if [ ${moves[$1]} == $player_1 ];then
      echo -e "${BLUE}The winners are the Xs!${END}"
      sleep 3
      clear
      echo -e "\e[33mDo you want to play again?${END}"
      echo -e "\e[4mCommands${END}: ${GREEN}(Y)Yes${END}   ${RED}(N or any other key)End${END}"
      read command
      if [ $command == "yes" ] || [ $command == "y" ] || [ $command == "Y" ] || [ $command == "Yes" ]
      then 
        playAgain
      else
        exit 
      fi
    else
      echo -e "${RED}The winners are the Os!${END}"
      sleep 3
      clear
      echo -e "\e[33mDo you want to play again?${END}"
      echo -e "\e[4mCommands${END}: ${GREEN}(Y)Yes${END}   ${RED}(N or any other key)End${END}"
      read command
      if [ $command == "yes" ] || [ $command == "y" ] || [ $command == "Y" ] || [ $command == "Yes" ]
      then 
        playAgain
      else
        exit 
      fi
    fi
  fi
}

checkWinner(){
  if [ $game_on == false ]; then return; fi
  checkMatch 0 1 2
  if [ $game_on == false ]; then return; fi
  checkMatch 3 4 5
  if [ $game_on == false ]; then return; fi
  checkMatch 6 7 8
  if [ $game_on == false ]; then return; fi
  checkMatch 0 4 8
  if [ $game_on == false ]; then return; fi
  checkMatch 2 4 6
  if [ $game_on == false ]; then return; fi
  checkMatch 0 3 6
  if [ $game_on == false ]; then return; fi
  checkMatch 1 4 7
  if [ $game_on == false ]; then return; fi
  checkMatch 2 5 8
  if [ $game_on == false ]; then return; fi

  if [ $turn -gt 9 ]; then 
    game_on=false
    echo -e "${GREEN}Its a draw!${END}"
    sleep 3
    clear
    echo -e "\e[33mDo you want to play again?${END}"
    echo -e "\e[4mCommands${END}: ${GREEN}(Y) Yes${END}   ${RED}(N or any other key) End${END}"
    read command
    if [ $command == "yes" ] || [ $command == "y" ] || [ $command == "Y" ] || [ $command == "Yes" ]
      then 
        playAgain
      else
        exit 
      fi
    fi
}

welcomeMessage
chooseFigure
printBoard

while $game_on
do
  playerPick
  printBoard
  checkWinner
done

function playAgain(){
  game_on=true
  withComputer=""
  
  turn=1
  moves=( 1 2 3 4 5 6 7 8 9 )
  welcomeMessage
  chooseFigure
  printBoard
  while $game_on
  do
    playerPick
    printBoard
    checkWinner
  done
}

playAgain "$@"; exit