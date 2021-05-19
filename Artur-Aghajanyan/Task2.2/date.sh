#!/bin/bash
x=$2
RED="\e[31m"
GREEN="\e[32m"
echo $(date)
case $1 in
	month)
		echo -e $GREEN
		echo $(date --date="-$x months")
		;;
	day)
		echo -e $GREEN
		echo $(date --date="-$x days")
		;;
	hour)
		echo -e $GREEN
		echo $GREEN $(date --date="-$x hours")
		;;
	minutes)
		echo -e $GREEN
		echo $GREEN $(date --date="-$x minutes")
		;;
	*)
		echo -e "${RED}unknown"
esac

