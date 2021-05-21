#!/bin/bash
echo "Enter Two numbers : "
read a
read symb
read b

case $symb in
	"+")
		  res=`echo $(($a + $b | bc))`
	  	  ;;
	"-")
			res=`echo $(($a - $b | bc))`
  		  ;;
  	"*")
			res=`echo $(($a * $b | bc))`
  	      ;;
  	"/")
			res=`echo $(($a / $b | bc))`
		  ;;
  	*)
		  ;;
esac
echo "Result : $res"
