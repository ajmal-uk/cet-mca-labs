print("<==== List without Even Number ====>")


list = [1,2,3,4,5,6,7,8,9,10]

for item in list:
    if item%2 == 0:
        list.remove(item)

print(list)