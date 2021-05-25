#!/bin/bash

arg=$1

if   [ -d "${arg}" ]
then echo "${arg} is a directory";
    echo `find $arg -type f | wc -l`
elif [ -f "${arg}" ]
then echo "${arg} is a file";
    FILESIZE=$(stat -c%s "$arg")
echo "Size of $FILENAME = $FILESIZE bytes."
else echo "${arg} is not valid";
     exit 1
fi
