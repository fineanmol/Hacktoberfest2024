def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Example usage:
arr = [5, 2, 4, 6, 1, 3]
insertion_sort(arr)
print(arr)  # Output: [1, 2, 3, 4, 5, 6]
