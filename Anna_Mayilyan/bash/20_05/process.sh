#!/bin/bash

proc_id=`pgrep $1`
echo $proc_id
proc_tree() {
  child=`pgrep -P $1`
  echo $child
  for i in $child
  do
    if [ -z $i ]
    then
      exit
    else
      echo  "$i "         
      proc_tree $i
    fi;
  done
}
proc_tree $proc_id
                   
