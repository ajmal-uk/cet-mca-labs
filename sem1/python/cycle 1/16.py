print("<==== GCD of Two Numbers ====>")

def gcd_gen(x, y):
    while y:
        x, y = y, x % y
    return x

print("GCD:", gcd_gen(48, 18))
