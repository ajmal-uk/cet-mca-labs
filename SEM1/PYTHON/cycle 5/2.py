print("<=== Read each row from a given csv file and print it as list of strings ===>")

import csv
try:
    with open("SEM1\PYTHON\cycle 5\data.csv", mode="r", newline="", encoding="utf-8") as f:
        reader = csv.reader(f)
        for row in reader:
            print(row)
except FileNotFoundError:
    print(f"CSV file not found")
except Exception as e:
    print(f"Error reading CSV: {e}")
