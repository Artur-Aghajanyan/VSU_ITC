number = input("Enter a number for checking: ")

if not number.isdigit():
    print("Input is string or small than 0")
else:
    number = int(number)
    sum = 0
    for i in range(1,number):
        if number%i == 0:
            sum = sum + i

    if(sum == number):
        print (number, "is a perfect number")
    else:
        print (number, "is not a perfect number")

