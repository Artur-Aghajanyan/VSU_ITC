#!/bin/bash

declare -A matrix
matrix[0,0]=*
matrix[0,1]=*
matrix[0,2]=*
matrix[1,0]=*
matrix[1,1]=*
matrix[1,2]=*
matrix[2,0]=*
matrix[2,1]=*
matrix[2,2]=*
echo -e "${matrix[0,0]} ${matrix[0,1]} ${matrix[0,2]} \n${matrix[1,0]} ${matrix[1,1]} ${matrix[1,2]} \n${matrix[2,0]} ${matrix[2,1]} ${matrix[2,2]} "

k=x
function print_matrix(){
	echo "please enter first number for row and second number for column"
  	read x
  	read y
  	if [[ ${matrix[$x,$y]} = "*" ]]; then
  		matrix[$x,$y]=$k 
  	else		 
		echo "inputing number is incorrect"
		print_matrix
  	fi        
  	if [[ $k = x ]]; then
  		k=o
  	else 
  		k=x
  	fi		   
	echo -e "${matrix[0,0]} ${matrix[0,1]} ${matrix[0,2]} \n${matrix[1,0]} ${matrix[1,1]} ${matrix[1,2]} \n${matrix[2,0]} ${matrix[2,1]} ${matrix[2,2]} "

}

function check_game_end(){
	game_end=0
	for (( i=0; i<3; i++ )) {
#iecho "${matrix[$i,0]}"
		if [ "${matrix[$i,0]}" != "*" ] && [ "${matrix[$i,0]}" == "${matrix[$i,1]}" ] && [ "${matrix[$i,0]}" == "${matrix[$i,2]}" ]; then 
			game_end=1
		fi
	}

	for (( j=0; j<3; j++ )){
		if [ "${matrix[0,$j]}" != "*" ] && [ "${matrix[0,$j]}" == "${matrix[1,$j]}" ] && [ "${matrix[0,$j]}" == "${matrix[2,$j]}" ]; then 
			game_end=1
		fi	
	}

	if [ "${matrix[0,0]}" != "*" ] && [ "${matrix[0,0]}" == "${matrix[1,1]}" ] && [ "${matrix[0,0]}" == "${matrix[2,2]}" ]; then 
		game_end=1
	fi

	if [ "${matrix[0,2]}" != "*" ] && [ "${matrix[0,2]}" == "${matrix[1,1]}" ] && [ "${matrix[0,2]}" == "${matrix[2,0]}" ]; then 
		game_end=1
	fi

	if [ "$game_end" == "1" ]; then
		echo "The game is ended "
		exit 0
	fi
}

for  (( i=0; i<9; ++i )) {
	print_matrix
	check_game_end
} 



