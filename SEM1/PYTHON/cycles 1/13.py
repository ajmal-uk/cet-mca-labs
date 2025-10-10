print("<==== Merge Two String Swapping the First Character ====>")

string1 = input("Enter First String : ")
string2 = input("Enter Second String : ")

new_string1 = string2[0] + string1[1:]  
new_string2 = string1[0] + string2[1:]

m_string = new_string1 + new_string2
print("Merged String:", m_string)