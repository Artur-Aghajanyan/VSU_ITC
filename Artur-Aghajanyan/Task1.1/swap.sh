#!/bin/bash
GREEN="\e[32m"
END="\e[0m"
file1="file1.txt"
file2="file2.txt"
echo "Befor swap file1 content: "
echo $(cat $file1)
echo "Befor swap file2 content: "
echo $(cat $file2)

mv $file1 cop_$file1
mv $file2 $file1
mv cop_$file1 $file2

echo ""
echo -e "${GREEN}After swap file1 content: ${END}"
echo $(cat $file1)
echo -e "${GREEN}After swap file2 content: ${END}"
echo $(cat $file2)
