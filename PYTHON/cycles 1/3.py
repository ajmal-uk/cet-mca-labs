print("<=== Largest Among Three Numbers ===>")

a = int(input("Enter the First Number : "))
b = int(input("Enter the Second Number : "))
c = int(input("Enter the Third Number : "))

print("<=== Using Manual Method ===>\n\n")
if a>b:
    if a>c:
        print(a,end='')
    else:
        print(c,end='')
else:
    if b>c:
        print(b,end='')
    else:
        print(c,end='')
print(" is Greater Number\n\n")


print("Using Math - Automatic\n")
print(max(a, b, c), " is Greater Number\n\n")
