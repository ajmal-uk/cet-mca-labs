print("<=== Read Specific Columns of given CSV file and print their content ===>")

import csv

csv_path = "SEM1\PYTHON\cycle 5\data.csv"
columns_to_read = ["Name", "Age"] 
try:
    with open(csv_path, mode="r", newline="", encoding="utf-8") as f:
        reader = csv.DictReader(f) 
        for row in reader:
            selected_data = [row[col] for col in columns_to_read if col in row]
            print(selected_data)
except FileNotFoundError:
    print(f"CSV file not found: {csv_path}")
except KeyError as e:
    print(f"Column not found in CSV: {e}")
except Exception as e:
    print(f"Error reading CSV: {e}")
