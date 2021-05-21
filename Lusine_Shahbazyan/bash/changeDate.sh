#!/bin/bash

echo "Enter frequency,that will be month, week, day, hour or minutes, and its value"
read -p "frequence = " frequency
read -p "value = " value
echo "Now is"
date 


echo "After running script date is"
case $frequency in
	month)
		date -d "+$value months"

		;;
	week)
		date -d "+$value weeks"
		;;
	day)
		date -d "+$value days"
		;;
	hour)
		date -d "+$value hours"
		;;
	minute)
		date -d "+$value minutes"
		;;
	*)
	     echo "It is wrong value of frequency.Please enter month, week, day, hour or minutes"

esac
#if [[ "$frequency" != "month" && "$frequency" != "day"  && "$frequency" != "week" && "$frequency" != "hour" && "$frequency" != "minutes" ]]; then
#    echo "It is wrong value of frequency.Please enter month, week, day, hour or minutes"
#fi


