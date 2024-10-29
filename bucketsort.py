def bucket_sort(arr):
    if len(arr) == 0:
        return arr

    # Step 1: Create empty buckets
    bucket_count = len(arr)
    max_val, min_val = max(arr), min(arr)
    bucket_range = (max_val - min_val) / bucket_count  # Range of each bucket
    buckets = [[] for _ in range(bucket_count)]

    # Step 2: Distribute elements into buckets
    for num in arr:
        index = int((num - min_val) / bucket_range)  # Find the correct bucket
        if index == bucket_count:  # Edge case for the max element
            index -= 1
        buckets[index].append(num)

    # Step 3: Sort individual buckets and concatenate them
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket))  # Sort each bucket and extend to sorted array

    return sorted_arr
