def two_sum(nums, target):
    num_map = {}
    
    for index, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], index]
        num_map[num] = index
        
    return None

# Example usage:
nums = [2, 7, 11, 15]
target = 9
result = two_sum(nums, target)

if result:
    print(f"Indices: {result[0]}, {result[1]}")
else:
    print("No two sum solution found.")
