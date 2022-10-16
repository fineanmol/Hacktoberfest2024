# Used in Java’s Arrays.sort() as well.

# The array is divided into blocks called Runs.
# These Runs are sorted using Insertion sort and then merged using Merge sort.

arr = [6, 2, 8, 9, 5, 3, 0, 15]
arr.sort()		# Since sort() does inplace sorting and returns None 
print(arr)

arr = [6, 2, 8, 9, 5, 3, 0, 15]
print(sorted(arr))		# so
