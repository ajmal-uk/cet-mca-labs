print("<==== Printing First and Last Colors From a String of Colors Seperated By Comma ====>")


colors = input("Enter a list of colors separated by commas: ")

color_list = [color for color in colors.split(',')]

if len(color_list) > 0:
    print("First color:", color_list[0])
    print("Last color:", color_list[-1])
else:
    print("No colors entered.")
