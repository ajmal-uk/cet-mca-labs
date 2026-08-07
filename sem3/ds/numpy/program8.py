#Save the Given array into text file and load it 


"""
np.savetxt() which is used to save the array into txt file 
np.loadtxt() which is user to load txt data into array

Functional Arguments: 
    1) File name 
    2) Array Name
"""

import numpy as np 


arr = np.arange(1,11)
np.savetxt("program8.txt",arr)

newarr = []

np.loadtxt("program8.txt",newarr)

print(newarr)