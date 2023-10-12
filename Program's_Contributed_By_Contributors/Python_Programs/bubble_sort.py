def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]  # swap the elements
                swapped = True
        # If no swaps occurred inside the loop, the list is sorted
        if not swapped:
            break
    return arr

# Test
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original list:", arr)
bubble_sort(arr)
print("Sorted list:", arr)
