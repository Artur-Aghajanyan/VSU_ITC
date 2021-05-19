#!/bin/bash
awk '{print $3}' list.txt > help1
awk '{print $1}' list.txt > help2

y=$(wc -l < list.txt)
let y=$y
let c=0
for (( j=1; j<=$y; j++ ))
do
x=$(sed '1q;d' help1)
let x=$x
        #echo $x
    for (( i=2; i<=$y-$c; i++ ))
    do
        let i=$i
        k=$(sed "${i}q;d" help1)
        let k=$k
        #echo $k
        if [ $x -gt $k ]
        then
            x=$k
            p=i
        fi
    done
   
   sed -i -e "{$p}d" help1
   cat help1
        echo $x
    echo "$x" >> file1
    c=$c+1
done
