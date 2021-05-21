#!/bin/bash

function getcpid {
  tp=`ps x -o %c $1`        #get childs pids of parent pid
  for i in $tp; do          #loop through childs
    if [ -z $i ]; then      #check if empty list
      exit                  #if empty: exit
    else                    #else
      echo -n "$i "         #print childs pid
    fi;
  done
}

getcpid $1
