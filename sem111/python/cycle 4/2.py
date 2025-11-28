print("<=== Time (Private , Operator Overloading) ===>\n")

class Time:
    def __init__(self, hour, minute, second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def constructorValues(self):
        print(f"Time -> {self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}")

    def __add__(self, other):
        total_seconds = (self.__hour * 3600 + self.__minute * 60 + self.__second) + \
                        (other.__hour * 3600 + other.__minute * 60 + other.__second)

        total_seconds %= 24 * 3600  
        hour = total_seconds // 3600
        total_seconds %= 3600
        minute = total_seconds // 60
        second = total_seconds % 60

        return Time(hour, minute, second)

    def __gt__(self, other):
        return (self.__hour, self.__minute, self.__second) > (other.__hour, other.__minute, other.__second)

    def __str__(self):
        return f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}"

t1 = Time(10, 45, 30)
t2 = Time(5, 20, 45)

print("Time 1:")
t1.constructorValues()

print("Time 2:")
t2.constructorValues()

t3 = t1 + t2
print("\nAfter Adding (t1 + t2):")
t3.constructorValues()

print(f"\nIs t1 > t2 ? {'Yes' if t1 > t2 else 'No'}")
