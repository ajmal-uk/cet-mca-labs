myList = []
postiveList = []
n = int(input("Enter the Range : "))
print("\nEnter the Elements One by One : \n")
for i in range(n):
    myList.append(int(input(f"Enter the {i} index Element : ")))

print("\nAll Elements is Entered Successfully!👌\n\nNew Positive List : ",end='')
for item in myList:
    if item > 0:
        postiveList.append(item)
        
print(postiveList)



