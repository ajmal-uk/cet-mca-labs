import math

print("<=== Area And Perimeter of Circle ===>")
radius = int(input("Enter the radius of Circle : "))
area = math.pi*math.pow(radius,2)
perimeter = 2*math.pi*radius

print(f"Area = {area}\n\nPerimeter = {perimeter}")
