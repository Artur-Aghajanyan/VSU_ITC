#!/bin/bash

echo "This script makes new folder named text and remove all files starting with text.* name into this folder"

echo "List of current folder is"
ls

echo "List of current folder after running script is" 
mkdir text
find . -name 'text.*' -exec mv -t text {} +

ls

echo "List of text folder is"
ls text
