#Create an array with elements of 0 - 20. and Convert the sign from 9-15

import numpy as np

arr = np.arange(0,21)

#Method 1

# for i, x in enumerate(arr):
#     if(x>=9 and x<=15):
#         arr[i] = -1*x

#Method 2

arr[9:16] *= -1

print(arr)