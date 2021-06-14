def get_divisors(n):
	x = 0
	for i in range(1,n):
		if n%i == 0:
			x+=i
	if n == x:
		print ("This number is perfect")
	else:
		print ("This number isn't perfect")
print ("Please input any positive integer") 
n = int(input())
get_divisors(n)
