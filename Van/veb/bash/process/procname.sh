#!/bin/bash
ARG=$1

function getcname {
  if [[ -z $ARG ]]; then
	ARG='init'
  fi
  pi=` pidof $ARG `
  cpids=`pgrep -P $pi`
  echo $cpids

  ps --ppid $pi | awk '{print $4}'

}

getcname $ARG
