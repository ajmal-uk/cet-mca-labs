import numpy as np

def read_array(name, size):
	return np.array([int(input(f"Enter element {i + 1} for {name}: ")) for i in range(size)])


array1_size = int(input("Enter the size of Array 1: "))
array2_size = int(input("Enter the size of Array 2: "))

array1 = read_array("Array 1", array1_size)
array2 = read_array("Array 2", array2_size)

print("Array 1:", array1)
print("Array 2:", array2)

if array1.shape != array2.shape:
	print("The arrays have different sizes, so element-wise comparison is not possible.")
else:
	print("Element-wise comparison:", array1 == array2)
	print("Arrays are equal:", np.array_equal(array1, array2))