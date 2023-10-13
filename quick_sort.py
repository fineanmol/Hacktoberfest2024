def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

# Take user input as a comma-separated list of integers
user_input = input("Enter a list of integers separated by commas: ")
user_list = [int(x.strip()) for x in user_input.split(',')]

# Call the quicksort function on the user input
sorted_list = quicksort(user_list)

# Print the sorted list
print("Sorted list:", sorted_list)
