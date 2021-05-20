#!bin/bash

echo person name and dept;
cat /dev/stdin | cut -d' ' -f 1,3 | sort
