print("<=== Number of digits in a number ===>")

number = int(input("Enter the number: "))

digits = 0

temp = abs(number)

if temp == 0:
    digits = 1
else:
    while temp > 0:
        temp = temp // 10
        digits += 1

print(f"Number of digits in {number} is {digits}")
