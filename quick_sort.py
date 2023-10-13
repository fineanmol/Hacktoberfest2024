# Define the quicksort function that sorts a list using the quicksort algorithm
def quicksort(arr):
    # Base case: If the list has 1 or fewer elements, it's already sorted
    if len(arr) <= 1:
        return arr
    else:
        # Choose the first element as the pivot
        pivot = arr[0]
        
        # Create two sublists: one for elements less than or equal to the pivot,
        # and one for elements greater than the pivot
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        
        # Recursively call quicksort on the two sublists, and concatenate them
        # with the pivot to return the sorted list
        return quicksort(less) + [pivot] + quicksort(greater)

# Take user input as a comma-separated list of integers
user_input = input("Enter a list of integers separated by commas: ")
user_list = [int(x.strip()) for x in user_input.split(',')]

# Call the quicksort function on the user input
sorted_list = quicksort(user_list)

# Print the sorted list
print("Sorted list:", sorted_list)
