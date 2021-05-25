#!/bin/bash

echo "Please enter name of process"
read processName

argument=$processName

getChildProcess(){
    if [ -z $processName ]
    then 
        echo "There is no entered name"
        exit
    fi
    PID=`pgrep $processName`
    if [ -z $PID ]
    then
        echo "There is no process by name $processName "
        exit
    else
        pstree -p $PID
    fi
 
}

getChildProcess $argument

