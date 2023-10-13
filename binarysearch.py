def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2  # Calculate the middle index

        if arr[mid] == target:
            return mid  # Target found, return its index
        elif arr[mid] < target:
            left = mid + 1  # Adjust the left boundary
        else:
            right = mid - 1  # Adjust the right boundary

    return -1  # Target not found in the array

if __name__ == "__main__":
    # Sample sorted array
    arr = [2, 4, 7, 10, 15, 20, 27, 30, 33, 40]
    
    # Target value to search for
    target = 15
    
    result = binary_search(arr, target)
    
    if result != -1:
        print(f"Element {target} found at index {result}")
    else:
        print(f"Element {target} not found in the array")
