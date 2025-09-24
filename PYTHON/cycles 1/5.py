print("<=== First n Multiples of Given Number ===>")

number = int(input("Enter the number to find the multiple of that : "))
n = int(input("Enter the multiple range : "))

for i in range(1, n+1):
    print(f"{i} x {number} = {i*number}")