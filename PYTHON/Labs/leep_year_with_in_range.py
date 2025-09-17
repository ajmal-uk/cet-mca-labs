print("<==== Leap Year Checker With In Range ====>")

s_year = int(input("Enter the Starting Year : "))
e_year = int(input("Enter the Ending Year : "))

for year in range(s_year,e_year+1):
    if year % 400 == 0:
        print(year)
    elif year % 100 == 0:
        pass
    elif year % 4 == 0:
        print(year)
    else:
        pass
