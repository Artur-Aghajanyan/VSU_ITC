#!/bin/bash
echo "Before deleting comments"
echo "************"
echo $(cat "comments")
sed -i 's:^#.*$::g' "comments"
sed -i 's:^//.*$::g' "comments"
echo ""
echo "After deleting comments"
echo "*************"
echo $(cat "comments")
