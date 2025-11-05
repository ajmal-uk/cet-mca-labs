print("<=== Read each row from a given csv file and print it as list of strings ===>")

import csv

with open("SEM1\PYTHON\cycle 5\data.csv","r") as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)
