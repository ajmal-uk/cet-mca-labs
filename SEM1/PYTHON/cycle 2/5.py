print("<=== Construct a Pattern Using Nested Loop ===>")

count = int(input("Enter the Count: "))

for i in range(count):
    for j in range(i + 1):
        print("*", end='')
    print()


print("<=== Next Pattern ===>")

i=j=0

for i in range(count+1):
    for space in range(count-i):
        print(" ",end='')

    for star in range(i):
        print("*",end="")
    print()



print("<=== Next Pattern ===>")

for i in range(1, count + 1):
    for space in range(count - i):
        print(" ", end='')

    for star in range(2 * i - 1):
        print("*", end='')

    print() 
