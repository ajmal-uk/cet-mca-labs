print("<=== Swap Numbers ===>")

a = int(input("Enter the First Number : "))
b = int(input("Enter the Second Number : "))

print(f"before swap a = {a} and b = {b}")

print("<=== Swaping Numbers ===>")
a = a+b
b = a-b
a = a-b

print(f"after swap a = {a} and b = {b}")