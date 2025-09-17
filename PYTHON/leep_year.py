print("<==== Leap Year Checker ====>")

year = int(input("Enter the year : "))

if year % 400 == 0:
    print(f"{year} is Leap Year")
elif year % 100 == 0:
    print(f"{year} is Not Leap Year")
elif year % 4 == 0:
    print(f"{year} is Leap Year")
else:
    print(f"{year} is Not Leap Year")
