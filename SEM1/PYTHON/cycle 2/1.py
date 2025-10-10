print("<=== Factorial Using Function ===>")

def fact(x):
    if x==1:
        return x
    else:
        return x*fact(x-1)
    
num = int(input("Enter the Number to Find the Factorial"))
print(fact(num))