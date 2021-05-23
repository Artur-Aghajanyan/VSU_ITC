#!/bin/bash
echo "Sorting files"
filenames=`ls`
for eachfile in $filenames
do
	DIRECTORY=${eachfile:0:4}

	if [ ! -d "$DIRECTORY" ]; then
		mkdir ${eachfile:0:4}	
	fi
	
	mv $eachfile ./$DIRECTORY
done
