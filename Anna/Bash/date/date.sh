#!/bin/bash 

read -p "Enter the freaquancy " frequancy
echo "frequancy=$frequancy"
read -p "Enter interval " interval
echo "interval=$interval"

echo `date`
 case $frequancy in
    "month")
echo `date -d "+$interval months"`
;;
    "week")
echo `date -d "+$interval weeks"`
;;
    "day")
echo `date -d "+$interval days"`
;;
    "hour")
echo `date -d "+$interval hours"`
;;
	"minute")
	echo `date -d "+$interval minutes"`
;;
	*)
echo "The date value is not correct!" 
;;
esac 
