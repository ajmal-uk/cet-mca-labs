print("<=== Write a Python Dictionary to a csv file , read the csv and display its content ===>")


import csv

data = {
    "Name": "Alok",
    "Age": 10,
    "Grade": "A"
}

with open("SEM1\PYTHON\cycle 5\csv.csv","w", newline="") as f:
    writer = csv.DictWriter(f,fieldnames=data.keys())
    writer.writeheader()
    writer.writerow(data)

with open("SEM1\PYTHON\cycle 5\csv.csv","r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row)
