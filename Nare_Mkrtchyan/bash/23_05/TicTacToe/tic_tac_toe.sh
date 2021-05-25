#!/bin/bash
board=( "." "." "." "." "." "." "." "." "." )

#########    COLORS    #########

Red_t='\033[3;31m'
Yel_t='\033[3;33m'
Blue_i_h='\033[3;94m'
BLUE='\033[0;44m'
WHITE='\033[0;47m'
NC='\033[0m' # No Color

############    VARIABLE DECLARATIONS    ###########

declare -i i=0   #for printing board
turn=false

############     PRINT BOARD (LINE 20-71)      #########  

#print line of board (1x3) 
printLineCube() {
  for (( j=0; j<3; ++j ))
  do
    printf "$1  ${NC}"
  done
}

#print line of board (1x9) 
printLine() {
  printf "  "
  printLineCube $1  
  printLineCube $2  
  printLineCube $1
  printf "\n"  
}

#print line with char (1x3)
print_x_o() {
  if [[ $2 = "." ]]
  then
    printf "$1%s${NC}" "      "
  else
    printf "$1  %s   ${NC}" "$2"
  fi
}

#print line with char (1x9)
printLine2() {
  printf "$i ${NC}"
  print_x_o $1 $3 
  print_x_o $2 $4 
  print_x_o $1 $5
  i=$((i+1))
  printf "\n"
}

#print board line cubes(3x9)
printBoardCube() {
  printLine $1 $2 
  printLine2 $1 $2 $3 $4 $5 
  printLine $1 $2 
}

#print board cubes(9x9)
printBoard() {
  printf "    0     1     2\n"
  printBoardCube ${BLUE} ${WHITE} ${board[0]} ${board[1]} ${board[2]}
  printBoardCube ${WHITE} ${BLUE} ${board[3]} ${board[4]} ${board[5]}
  printBoardCube ${BLUE} ${WHITE} ${board[6]} ${board[7]} ${board[8]}
  i=0
}

##############################################

##########   RESET  ###########

reset() {
  enterFirstSymbol
  board=( "." "." "." "." "." "." "." "." "." )
  turn=false
  printBoard
}

#########   ENTER SYMBOLS TO PLAY    ##########

enterFirstSymbol() {
  echo -e "${Blue_i_h}Enter symbols to play.${NC}"
  echo -e "${Blue_i_h}Enter only one symbol, it can't be ${Yel_t}empty${Blue_i_h} or ${Yel_t}'.'${Blue_i_h}.${NC}"
  printf "${Blue_i_h}Enter first symbol:${NC} "
  read fsym
  if checkSymbol $fsym; then
    enterFirstSymbol
  else
    enterSecondSymbol
  fi
}

enterSecondSymbol() {
  printf "${Blue_i_h}Enter second symbol:${NC} "
  read ssym
  if [[ $ssym != $fsym ]]
  then
    if checkSymbol $ssym; then
      enterSecondSymbol
    else 
      echo -e "${Yel_t}Type reset to start again.${NC}"
      echo -e "${Yel_t}'Ctrl' c to exit.${NC}"
    fi
  else
    echo -e "${Yel_t}Entered symbol is in use. Try again.${NC}"
    enterSecondSymbol
  fi
}

#########  SYMBOL  CHECKING  ##########

checkSymbol() {
  if [[ $1 = "" ]]; then
    echo -e "Symbol ${Red_t}can't be empty${NC}."
    return 0
  elif [[ $1 = "." ]]; then
    echo -e "Symbol ${Red_t}can't be '.'${NC}."
    return 0
  elif [[ ${#1} -gt 1 ]]; then
    echo -e "Enter ${Red_t}only one${NC} symbol."
    return 0
  fi
  return 1
}

########    PLAYER INPUTS   ###########

enterField() {
  if [[ "$turn" = false ]]
  then
    echo -e "${Blue_i_h}$1's turn${NC} "
  else 
    echo -e "${Blue_i_h}$2's turn${NC} "
  fi
  printf "${Blue_i_h}Enter field:${NC} "
  read field
  if checkFieldSyntax $field 
  then
    if checkFieldEmpty $field
    then
      first=${field:0:1}
      last=${field: -1}
      if [[ "$turn" = false ]]
      then
        turn=true
        board[$(($first*3+$last))]="$1"
      else 
        turn=false
        board[$(($first*3+$last))]="$2"
      fi
      printBoard
    else 
      return
    fi
  else
    return 
  fi
}

##########   FIELD CHEKING   ##############

checkFieldEmpty() {
  first=${1:0:1}
  last=${1: -1}
  if [[ ${board[$(($first*3+$last))]} != "." ]]
  then
    echo -e "${Red_t}$1${NC} field is ${Yel_t}not empty${NC}"
    return 1
  fi
}

checkFieldSyntax() {
  if [[ $1 = "" ]]
  then
    echo "Field can't be empty."
    return 1
  fi
  if [[ $1 = "reset" ]]; then
    reset
    return 1
  fi
  if [[ $1 != "00" && $1 != "01" && $1 != "02" && $1 != "10" && $1 != "11" && $1 != "12" && $1 != "20" && $1 != "21" && $1 != "22" ]]
  then
    echo -e "You entered ${Red_t}$1${NC} , but field must be one of ${Yel_t}00 01 02 10 11 12 20 21 22${NC}"
    return 1
  fi
  return 0
}

################   CHECK WINNER    ###############

checkAnswer() {
  printf "${Yel_t}Do you want to play again?(type yes(can also be y or uppercase), or no(n or uppercase)): ${NC}"
  read answer
  answer="$(echo $answer | tr '[:upper:]' '[:lower:]')"
  if [[ $answer = "yes" || $answer = "y" ]];then
    reset     
    return 0
  fi
  if [[ $answer = "no" || $answer = "n" ]];then
    exit
  fi
}

checkDraw() {
  if [[ ${board[0]} != "." && ${board[1]} != "." && ${board[2]} != "." && ${board[3]} != "." && ${board[4]} != "." && ${board[5]} != "." && ${board[6]} != "." && ${board[7]} != "." && ${board[8]} != "." ]]
  then 
    echo -e "${Yel_t}Draw${NC}"
    checkAnswer
  fi
}

winORnotOneCase() {
  if [[ ${board[$1]} = ${board[$2]} && ${board[$1]} = ${board[$3]} && ${board[$1]} != "." ]]; then
    echo -e "${Yel_t}Wins${NC} ${Red_t}${board[$1]}${NC}"
    checkAnswer
  fi
}

winORnot() {
  winORnotOneCase 0 1 2 
  winORnotOneCase 3 4 5 
  winORnotOneCase 6 7 8 
  winORnotOneCase 0 3 6 
  winORnotOneCase 1 4 7 
  winORnotOneCase 2 5 8
  winORnotOneCase 0 4 8 
  winORnotOneCase 6 4 2 
}

#############  START   ############

reset
while :
do
  enterField $fsym $ssym
  winORnot
  checkDraw
done
