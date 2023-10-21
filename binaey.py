def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        # Check if the target is present at mid
        if arr[mid] == target:
            return mid
        
        # If the target is greater, ignore left half
        elif arr[mid] < target:
            left = mid + 1
        
        # If the target is smaller, ignore right half
        else:
            right = mid - 1
    
    # If the target is not in the array
    return -1

# Example usage
arr = [2, 4, 7, 10, 14, 17, 19, 22]
target = 14
result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found in the array")
