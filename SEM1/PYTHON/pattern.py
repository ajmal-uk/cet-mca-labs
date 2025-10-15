from math import *
n = int(input("Enter the number of lines :"))
for i in range(n):
    print((n-i)*" ",end="")
    for j in range(i+1):
        print(comb(i,j),end=" ")
    print("")
