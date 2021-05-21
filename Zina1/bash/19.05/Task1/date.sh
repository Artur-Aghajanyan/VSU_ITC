#!/bin/bash

case $1 in
    month)
        echo "$(date -d "+$2 months")"
        ;;

    week)
        echo "$(date -d "+$2 weeks")"
        ;;

    day)
        echo "$(date -d "+$2 days")"
        ;;

    hour)
        echo "$(date -d "+$2 hours")"
        ;;

    minutes)
        echo "$(date -d "+$2 minutes")"
        ;;

    *)
        if [ "$#" -lt 2 ]
        then
            echo "enter 2 arguments to get some result"
        else
            echo "given wrong value to frequency argument, enter something from mounth, week, day, hour or minutes"
        fi
        ;;
esac
