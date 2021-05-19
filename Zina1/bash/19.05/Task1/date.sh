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
        echo "given wrong value"
        ;;
esac
