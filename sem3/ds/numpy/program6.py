# Create an array and compute sum of all elements, columns, and each row

import numpy as np

matrix = np.array([[1,2,3],[4,5,6],[7,8,9]])
print(matrix)

print("Sum of all elements:", np.sum(matrix))
print("Sum of each row:", np.sum(matrix, axis=1))
print("Sum of each column:", np.sum(matrix, axis=0))