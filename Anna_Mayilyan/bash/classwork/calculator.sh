#!/bin/bash
  
read  -p "Enter first value " a
if [ -z $a ]; then
echo "empty field"
exec $0
fi
read -p "Enter operation " o
if [ -z $o ]; then
echo "empty field"
exec $0
fi

read -p "Enter second value " b
if [ -z $b ]; then
echo "empty field"
exec $0
fi


  
# Switch Case to perform
# calulator operations
case $o in
  "+")res=`echo $a + $b | bc`
  ;;
  "-")res=`echo $a - $b | bc`
  ;;
  "*")res=`echo $a \* $b | bc`
  ;;
  "/")res=`echo "scale=2; $a / $b" | bc`
  ;;
  *)
	echo "Not valid operation"
  ;;
esac

echo "Result : $res"
