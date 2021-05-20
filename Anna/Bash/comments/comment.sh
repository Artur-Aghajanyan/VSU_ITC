#!/bin/bash

sed -i 's://.*::' comment
awk 'NR==1 || NR==2 || !/^#/' comment
