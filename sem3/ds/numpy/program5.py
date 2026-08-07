#create a 5x5 Zero matrix on the main Diagonal (1,2,3,4,5)


import numpy as np

#Method 1

# matrix = np.zeros((5,5),dtype=int)
# for i in range(len(matrix)):
#     for j in range(len(matrix)):
#         if i == j:
#             matrix[i][j] = i + 1



#Method 2

matrix = np.diag(np.arange(1, 6))

print(matrix)