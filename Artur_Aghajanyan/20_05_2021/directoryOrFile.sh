#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
END="\e[0m"

until ([ ! -z $NAME ])
do
	echo -e "${GREEN}It must be Name File or Directory: $END"
	read NAME
done

function findIt {
	if [ -d "${1}" ] ; then
	    echo -e "This is Directory: ${GREEN}${1}${END}";
		echo -e "There are: ${GREEN}$(ls ${1} | wc -l)${END} elements"
	else
		if [ -f "${1}" ]; then
			myfilesize=$(wc -c ${1} | awk '{print $1}')

			echo -e"This is file: ${GREEN}${1}${END}"
			echo -e "File of size: ${GREEN}${myfilesize}${END}";
		else
	        echo -e "${RED}${1} is not valid";
			exit
		fi
	fi
}

findIt $NAME
