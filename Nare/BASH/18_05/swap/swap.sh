echo "Content of first file:"
cat first
echo "Content of second file:"
cat second
x=`cat first`
cp second first
echo "$x" > second
echo "Content of first file:"
cat first
echo "Content of second file:"
cat second
