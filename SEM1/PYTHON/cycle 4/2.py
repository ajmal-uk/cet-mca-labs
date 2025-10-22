print("<=== Time(Private , Overloading) ===>\n\n")


class Time:
    def __init__(self, time, day):
        self.__time = time
        self.__day = day

    def constructorValues(self):
        print(f"Time : {self.__time} , Day : {self.__day}")
    
    def display(time):
        print(f"time is {time}")

    def display(time, day):
        print(f"time is {time} and day is {day}")


import datetime

today = datetime.datetime.today() 
current_time = today.time()

timeObj = Time(current_time, today)

timeObj.display(current_time)
timeObj.display(current_time,today)



timeObj.constructorValues()