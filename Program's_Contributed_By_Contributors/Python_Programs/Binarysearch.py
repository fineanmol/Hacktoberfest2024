import random
import time

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Generate a sorted list of numbers for testing
sorted_list = sorted(random.sample(range(1, 1000000), 100000))

# Select a random target element from the list
target = random.choice(sorted_list)

# Perform a linear search and measure the time taken
start_time = time.time()
linear_result = linear_search(sorted_list, target)
linear_time = time.time() - start_time

# Perform a binary search and measure the time taken
start_time = time.time()
binary_result = binary_search(sorted_list, target)
binary_time = time.time() - start_time

if linear_result != -1:
    print(f"Linear Search: Element {target} found at index {linear_result}.")
    print(f"Time taken for Linear Search: {linear_time:.6f} seconds")
else:
    print(f"Linear Search: Element {target} not found in the list.")

if binary_result != -1:
    print(f"Binary Search: Element {target} found at index {binary_result}.")
    print(f"Time taken for Binary Search: {binary_time:.6f} seconds")
else:
    print(f"Binary Search: Element {target} not found in the list.")
