print("<=== Adding 'ing' at the end of given string. if it already ends with 'ing', add 'ly' ===>")

string = input("Enter the string: ")

string_last_3_char = string[-3:]

if string_last_3_char == "ing":
    string += "ly"
else:
    string += "ing"

print(string)