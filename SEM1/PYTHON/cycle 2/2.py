print("<=== Fibonacci Series of N Terms ===>")

def fib(n):
    if n <= 0:
        print("Nothing")
        return
    elif n == 1:
        print("0")
        return
    elif n == 2:
        print("0, 1")
        return

    a, b = 0, 1
    print(a, b, end=', ')
    for _ in range(n - 2):
        c = a + b
        print(c, end=', ' if _ < n - 3 else '')
        a, b = b, c
    print() 

num = int(input("Enter the Range: "))
fib(num)
