#!/bin/bash

echo 11111 $'\n'#22222 $'\n'33333 $'\n'//44444 $'\n'55555 > text.txt
echo Before removing! $'\n'
cat text.txt
sed -i 's:^#.*$::g' text.txt
sed -i 's:^//.*$::g' text.txt
sed -i '/^[[:space:]]*$/d' text.txt
echo $'\n'After removing! $'\n'
cat text.txt
