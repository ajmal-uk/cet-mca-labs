print("<=== Copy Odd Lines of File To Another ===>")

Data = """My name is Ajmal
I studyig in College of Engineing Trivandrum
The couse is MCA
The year is First Year"""

with open("file1.txt", "w") as f1:
    f1.write(Data)

with open("file1.txt", "r") as f1:
    lines = f1.readlines()

odd_lines = [line for idx, line in enumerate(lines) if idx % 2 == 0]
print(odd_lines)

with open("file2.txt", "w") as f2:
    f2.writelines(odd_lines)

print("Odd lines copied successfully!")
