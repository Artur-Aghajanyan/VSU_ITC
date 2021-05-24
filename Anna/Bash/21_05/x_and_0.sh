#!/bin/bash

first="X"
second="O"

round=1
state=true

places=( 1 2 3 4 5 6 7 8 9 )

show() {
  echo " ${places[0]} | ${places[1]} | ${places[2]} "
  echo "-----------"
  echo " ${places[3]} | ${places[4]} | ${places[5]} "
  echo "-----------"
  echo " ${places[6]} | ${places[7]} | ${places[8]} "
  echo "***********"
}



choose_players(){
	if [[ $(($round % 2)) == 0 ]]
  	then
    player=$second
    echo -n "Player 0 enter the cell: "
 	 else
    echo -n "Player X enter the cell: "
    player=$first
  	fi

  	read choosen_cell
  	space=${places[($choosen_cell -1)]} 
	[ -n "$choosen_cell" ] && [ "$choosen_cell" -eq "$choosen_cell" ] &&  [ -n "$space" ] && [ "$space" -eq "$space" ] 2>/dev/null
	if [ $? -ne 0 ] || [ "$choosen_cell" -lt 1 ] || [ "$choosen_cell" -gt 9 ] ; 
then 
    echo "You can not choose this cell."
    
	choose_players
  else

    places[($choosen_cell -1)]=$player
    ((round=round+1))
  fi
  space=${places[($choosen_cell-1)]} 
}



check() {
  if  [[ ${places[$1]} == ${places[$2]} ]] && [[ ${places[$2]} == ${places[$3]} ]]; then
    state=false
  fi
  if [ $state == false ]; then
    if [ ${places[$1]} == 'x' ];then
      echo "Player second wins!"
      return
    else
      echo "player first wins!"
      return
    fi
  fi
}

find_winner(){
 	if [ $state == false ]; then return; fi
 	check 0 1 2
	if [ $state == false ]; then return; fi
  	check 3 4 5
  	if [ $state == false ]; then return; fi
  	check 6 7 8
  	if [ $state == false ]; then return; fi
  	check 0 4 8
  	if [ $state == false ]; then return; fi
  	check 2 4 6
  	if [ $state == false ]; then return; fi
  	check 0 3 6
  	if [ $state == false ]; then return; fi
  	check 1 4 7
  	if [ $state == false ]; then return; fi
  	check 2 5 8
  	if [ $state == false ]; then return; fi

  	if [ $round -gt 9 ]; then 
    state=false;
    echo "Nobody wins!"
  fi


}

show
while $state
do
	choose_players
	show
  	find_winner
done



restart_game(){

  	echo "Do you want to play again (yes/no) ?"
 	read answer
	if [ yes = "$answer" ]; then
   	exec $0
	fi
}
restart_game
