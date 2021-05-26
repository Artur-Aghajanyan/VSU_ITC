def pascal_numbers(n):
	for i in range(0, n):

		for j in range(0, i + 1):
			print (counting_factorial(i, j),
					 " ", end="")
		print ()

def factorial(num):
	if num == 1 or num == 0:
		return 1
	else:
		return num * factorial(num-1)

def counting_factorial(i, j):
	return int(factorial(i)/(factorial(i-j)*factorial(j)))

n = int(input())
pascal_numbers(n)
