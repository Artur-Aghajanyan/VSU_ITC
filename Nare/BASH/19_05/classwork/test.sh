#!/bin/bash
awk '{print $3}' list.txt > help1
awk '{print $1}' list.txt > help2

cat list.txt
y=$(wc -l < list.txt)
let y=$y
let c=0
for (( j=1; j<$y-1; j++ ))
do
x=$(sed '1q;d' help1)
let x=$x
    for (( i=1; i<=$y-$c; i++ ))
    do
        let i=$i
        k=$(sed "${i}q;d" help1)
        if [ $x -gt $k ]
        then
            x=$k
            p=$i
        fi
    done
z=$(sed "${p}q;d" help2)
   sed -i "${p}d" help1
   sed -i "${p}d" help2
    echo "$z $x" >> file1
    c=$c+1
done
x=$(sed '1q;d' help1)
let x=$x
y=$(sed '2q;d' help1)
let y=$y
if [ $x -gt $y ]
then 
    z=$(sed '2q;d' help2)
    echo "$z $y" >> file1
    z=$(sed '1q;d' help2)
    echo "$z $x" >> file1
else 
    z=$(sed '1q;d' help2)
    echo "$z $x" >> file1
    z=$(sed '2q;d' help2)
    echo "$z $y" >> file1
fi
cat file1
rm file1 help1 help2
