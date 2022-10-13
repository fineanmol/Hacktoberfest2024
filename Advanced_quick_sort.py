
def insertion_sort(arr, low, n):
	for i in range(low + 1, n + 1):
		val = arr[i]
		j = i
		while j>low and arr[j-1]>val:
			arr[j]= arr[j-1]
			j-= 1
		arr[j]= val


def partition(arr, low, high):
	pivot = arr[high]
	i = j = low
	for i in range(low, high):
		if arr[i]<pivot:
			a[i], a[j]= a[j], a[i]
			j+= 1
	a[j], a[high]= a[high], a[j]
	return j


def quick_sort(arr, low, high):
	if low<high:
		pivot = partition(arr, low, high)
		quick_sort(arr, low, pivot-1)
		quick_sort(arr, pivot + 1, high)
		return arr

def hybrid_quick_sort(arr, low, high):
	while low<high:

		if high-low + 1<10:
			insertion_sort(arr, low, high)
			break

		else:
			pivot = partition(arr, low, high)

		
			if pivot-low<high-pivot:
				hybrid_quick_sort(arr, low, pivot-1)
				low = pivot + 1
			else:
		
				hybrid_quick_sort(arr, pivot + 1, high)
				high = pivot-1



a = [ 24, 97, 40, 67, 88, 85, 15,
	66, 53, 44, 26, 48, 16, 52,
	45, 23, 90, 18, 49, 80, 23 ]
hybrid_quick_sort(a, 0, 20)
print(a)
