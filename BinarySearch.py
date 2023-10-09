def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid  # Element found, return the index
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # Element not found

# Input: Sorted list of numbers
input_list = input("Enter a sorted list of numbers separated by spaces: ").split()
sorted_list = [int(x) for x in input_list]
target = int(input("Enter the element you want to find: "))

index = binary_search(sorted_list, target)

if index != -1:
    print(f"Element {target} found at index {index}.")
else:
    print(f"Element {target} not found in the list.")
