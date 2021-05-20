#!/bin/bash

function process
{
  if [ -z $1 ] || [[ $1 =~ ^[0-9]+$ ]]
  then
    echo 'Plz, write before ./process.sh process name(Not PID)!'
    exit
  fi
  pr_id=$(pgrep $1)
  if [ -z $pr_id ]
  then
    echo The process is not found!
    exit
  fi
  echo "$1 PID - $pr_id"$'\n'
  echo 'Childs'$'\n'
  ps -p $(pgrep -P $pr_id)
}

process $1
