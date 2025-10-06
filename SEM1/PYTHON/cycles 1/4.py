print("<=== Arithmetic Operations ===>")

number1 = int(input("Enter First Number: "))
number2 = int(input("Enter Second Number: "))

print(f"Addition : {number1 + number2}")
print(f"Subtraction : {number1 - number2}")
print(f"Multiplication : {number1 * number2}")

if number2 != 0:
    print(f"Division : {number1 / number2}")
    print(f"Modulus : {number1 % number2}")
else:
    print("Division and Modulus: Cannot divide by zero")
