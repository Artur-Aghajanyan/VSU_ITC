#!/bin/bash

function getcpid {
  tp=`ps x -o "%c" $1`
  for i in $tp; do
    if [ -z $i ]; then
      exit
    else
      echo -n "$i "         
    fi;
  done
}

getcpid $1
