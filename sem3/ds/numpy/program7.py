#Create a 1-D array and setup values and reshape that into 2-D array and Do the sum ops 

import numpy as np

arr = np.arange(1,10)
matrix = arr.reshape(3, 3)
print(matrix)
print("Sum of all elements:", np.sum(matrix))
print("Sum of each row:", np.sum(matrix, axis=1))
print("Sum of each column:", np.sum(matrix, axis=0))