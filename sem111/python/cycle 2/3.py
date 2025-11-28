print("<=== Character Frequency in a String ===>")

string = input("Enter the string: ")

frequency = {}

for char in string:
    if char in frequency:
        frequency[char] += 1
    else:
        frequency[char] = 1

print("\nCharacter Frequencies:")
for char, count in frequency.items():
    print(f"'{char}': {count}")
