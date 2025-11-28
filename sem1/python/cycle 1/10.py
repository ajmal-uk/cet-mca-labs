import math

print("<==== Root of Quadratic Equation ====>")

a = int(input("Enter the Coefficient of x^2 : "))
b = int(input("Enter the Coefficient of x : "))
c = int(input("Enter the Constant : "))

discriminant = math.pow(b,2) - 4*a*c

if discriminant > 0:
    root1 = (-b + math.sqrt(discriminant)) / (2*a)
    root2 = (-b - math.sqrt(discriminant)) / (2*a)
    print(f"The roots are real and distinct: {root1} and {root2}")
elif discriminant == 0:
    root = -b / (2*a)
    print(f"The roots are real and equal: {root}")
else:
    real_part = -b / (2*a)
    imaginary_part = math.sqrt(-discriminant) / (2*a)
    print(f"The roots are complex:")
    print(f"{real_part} + {imaginary_part}i")
    print(f"{real_part} - {imaginary_part}i")
