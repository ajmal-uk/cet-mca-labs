print("<=== Graphics ===>")

from turtle import *

draw = Turtle()

draw.fillcolor("red")
draw.begin_fill()

for i in range(4):
    draw.forward(100)
    draw.left(90)

draw.end_fill()
done()
