import random

def quick_sort_randomized(arr):
    if len(arr) <= 1:
        return arr

    pivot = random.choice(arr)
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort_randomized(left) + middle + quick_sort_randomized(right)

print('random quick sort')
