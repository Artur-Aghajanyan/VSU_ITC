echo "file1"
cat file1
echo "file2"
cat file2
echo "*****Swaping*****"
x=$(cat file1)
cp file2 file1
echo "$x" > file2
echo "file1"
cat file1
echo "file2"
cat file2
