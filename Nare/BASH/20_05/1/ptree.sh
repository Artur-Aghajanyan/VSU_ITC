#!/bin/bash
if [[ $# -lt 1 || $# -gt 1 ]]
then
  echo "Enter only one argument(process name)" 
  exit
fi
pname=$1
ppid=`pgrep $1`
echo $ppid
ptree() {
  if [ -z $1 ]
  then
    echo "There are no process named $pname" 
    exit
  fi
  newppid=`pgrep -P $1`   
  echo $newppid
  for i in $newppid
  do     
    if [ -z $i ]
    then      
      exit                  
    else                    
      echo -n "$i "         
      ptree $i     
    fi;
  done
}
ptree $ppid
