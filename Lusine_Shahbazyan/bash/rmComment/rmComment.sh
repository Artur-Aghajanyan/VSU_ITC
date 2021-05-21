#!/bin/bash

sed '/^#/d' 1.txt
sed -i 's:^//.*$::g' 1.txt
echo "This script remove all commented lines from 1.txt file and print result in console"



