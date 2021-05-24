#!/bin/bash

function a {
    a=$(find $1 -type f)
    b=$(find $1 -type d)

    for x in $a
    do
        echo "Size File"
        echo $(du -h $x)
    done

    for x1 in $b
    do
        echo "Directory: Count of items" 
        echo -n $x1': '
        echo $(find $x1 -type f | wc -l)
    done
}

a $1
