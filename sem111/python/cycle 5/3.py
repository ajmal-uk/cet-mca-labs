print("<=== Read Specific Columns of given CSV file and print their content ===>")

import csv

columns_to_read = ["Name", "Age"] 

with open("SEM1\PYTHON\cycle 5\data.csv", "r") as f:
    reader = csv.DictReader(f) 
    for row in reader:
        selected_data = [row[col] for col in columns_to_read if col in row]
        print(selected_data)
