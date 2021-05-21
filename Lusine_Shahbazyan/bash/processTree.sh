#!/bin/bash

echo "This script displays all child process tree"
echo "Please enter only name of parent process"

read processName
$1=$processName
flag=`pgrep -x mysqld >/dev/null`
echo $flag
getChildProcess() {
if [ -z $processName ]
then 
    echo "There is no entered name"
    exit
fi
    
    PID=`pgrep $processName`
    pstree -p $PID
 
}

getChildProcess $1

