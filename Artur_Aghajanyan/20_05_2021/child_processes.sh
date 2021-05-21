#!/bin/bash
RED="\e[31m"
GREEN="\e[32m"
END="\e[0m"
psTree () {
	until ([ ! -z $namePS ] && [[ ! $namePS =~ ^[0-9]+$ ]])
	do
		echo -e "${GREEN}It must be process Name: $END"
		read namePS
	done

	pid=$(pgrep $namePS)

	if [ -z $pid]
	then
		echo -e "${RED}There is not process like that"
		exit
	fi
	ps --ppid $pid
}

psTree
