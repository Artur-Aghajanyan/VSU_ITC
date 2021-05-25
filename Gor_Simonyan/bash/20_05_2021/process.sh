#!/bin/bash

function process
{
  if [ -z $1 ] || [[ $1 =~ ^[0-9]+$ ]]
  then
    echo 'Plz, write before ./process.sh process name(Not PID)!'
    exit
  fi
  pr_id=$(pgrep $1)
  word=$(echo $pr_id | awk '{print $1;}')
  if [ -z $word ]
  then
    echo The process is not found!
    exit
  fi
  echo "$1 PIDs - $word"$'\n'
  echo 'Childs'$'\n'
  ps -p $(pgrep -P $word)
}

process $1
