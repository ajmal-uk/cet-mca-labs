print("<==== Sort Dictionary : Based on Items ====>")


items = {}
items["A"] = 110
items["B"] = 0
items["C"] = 10
items["D"] = 50
sorted_items = sorted(items.items(), key=lambda x: x[1])

print("Sorted Items (by values):")
for key, value in sorted_items:
    print(f"{key}: {value}")