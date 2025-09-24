print("<==== Exchage the first and last charecters of String ====>")

string = input("Enter a String : ")

first = string[0]
last = string[-1]
mid = string[1:-1]

print(f"Changed String is : {last}{mid}{first}")