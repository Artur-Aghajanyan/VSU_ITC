#!/bin/bash

function directory
{
  dir=$1
  if ! [ -d $1 ] || [ -z $1 ]
  then
    echo "$1 is not directory,plz write directory!"
    exit
  fi
  
  echo ${dir##*//} contain:$'\n'
  ls $dir
  echo $'\n'

  for file in $1/*
  do
    if [ -f $file ]
    then
      echo ${file##*//} - is a file! Size - `stat --printf="%s" $file`
    elif [ -d $file ]
    then
      echo "${file##*//} - is a directory! Its contain `ls $file | wc -l` files"$'\n'
      directory $file
    fi
  done
}

directory $1
