#!/bin/bash
arg=$1
function getcpname() {
  ppid=`pidof $arg`	
    all=`ps --ppid $z`
	ps --ppid $ppid | awk '{print $4}' 
}

getcpname $1

