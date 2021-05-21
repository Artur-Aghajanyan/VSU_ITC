#!/bin/bash

echo "This script remove all commented lines from 1.txt file and print result in console"
cat 1.txt
sed -i 's:^#.*$::g'  1.txt
sed -i 's:^//.*$::g' 1.txt
echo "After running scrit"
cat 1.txt



