def hybrid_search(arr, target):
    n = len(arr)
    linear_search_threshold = 10  # You can adjust this threshold based on your data and performance testing.

    def linear_search(left, right):
        for i in range(left, right + 1):
            if arr[i] == target:
                return i
        return -1

    def binary_search(left, right):
        while left <= right:
            mid = left + (right - left) // 2

            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1

    if n <= linear_search_threshold:
        return linear_search(0, n - 1)
    else:
        split_point = binary_search(0, n - 1)
        if split_point == -1:
            return -1
        if arr[split_point] == target:
            return split_point
        left_result = linear_search(0, split_point - 1)
        if left_result != -1:
            return left_result
        return binary_search(split_point + 1, n - 1)

# Example usage:
sorted_list = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
target = 7
result = hybrid_search(sorted_list, target)

if result != -1:
    print(f"Found {target} at index {result}")
else:
    print(f"{target} not found in the list")

