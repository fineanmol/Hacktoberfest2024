def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        # Flag to optimize the algorithm by checking if any swaps are made in this pass
        swapped = False

        # Last i elements are already in place, so we don't need to check them again
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap the elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # If no two elements were swapped in this pass, the list is already sorted
        if not swapped:
            break

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(arr)
print("Sorted array:", arr)
