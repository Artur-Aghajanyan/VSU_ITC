def print_fibonacci (n):
	x=0
	y=1
	
	if n == 1: 
		print (x)
	if n == 2:
		print (y)
	if n > 2:
		for i in range(2,n):
			z=x+y
			x=y
			y=z
			
		print(z)
n = int(input())
print_fibonacci(n)
