def pascal_triangle(n):
    print("\n", "pascals triangle for" , n , "\n")
    trow = [1]
    y = [0]
    for x in range(max(0,n)):
        print(" " , trow)
        trow=[l+r for l,r in zip(trow+y, y+trow)]
    return n>=1

pascal_triangle(10) 
