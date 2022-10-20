def insertion_sort(arr):

	for i in range(1, len(arr)):

		key = arr[i]
    
		j = i-1
		while(j >= 0 and key < arr[j]):
				arr[j + 1] = arr[j]
				j -= 1
		arr[j + 1] = key


arr = [23, 77, 4, 54, 66]
insertion_sort(arr)
for i in range(len(arr)):
  print (f" {arr[i]}")
