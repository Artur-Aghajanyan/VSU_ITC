#!/bin/bash

case $1 in
	month)
		date -d "+$2 months"
		;;
	week)
		date -d "+$2 weeks"
		;;
	day)
		date -d "+$2 days"
		;;
	hour)
		date -d "+$2 hours"
		;;
	minute)
		date -d "+$2 minutes"
		;;
	*)
		echo Invalid value $1
esac	

