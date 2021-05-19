#!/bin/bash
if [ "$#" -lt 2 ]; then
    echo "Illegal number of parameters. Enter 2 parameters"
fi
case $1 in
    month|week|day|hour|minutes)
    date -d "+$2 $1" '+%F %T'
    ;;
    *)
        echo "First parameter should be month or week or day or hour or minutes"
esac
