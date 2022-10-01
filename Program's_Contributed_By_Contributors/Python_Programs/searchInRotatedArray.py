def rotated_search_helper(arr, low, high, key):
    if low > high:
        return "No match"

    mid = low + ((high - low) // 2)

    if arr[mid] == key:
        return mid

    if arr[low] <= arr[mid] and key <= arr[mid] and key >= arr[low]:
        return rotated_search_helper(arr, low, mid - 1, key)

    elif arr[mid] <= arr[high] and key >= arr[mid] and key <= arr[high]:
        return rotated_search_helper(arr, mid + 1, high, key)

    elif arr[high] <= arr[mid]:
        return rotated_search_helper(arr, mid + 1, high, key)

    elif arr[low] >= arr[mid]:
        return rotated_search_helper(arr, low, mid - 1, key)

    return -1


def rotated_search(arr, key):
    return rotated_search_helper(arr, 0, len(arr) - 1, key)

input_arr = []
n = int(input("Enter number of elements : "))

print("Enter array values one by one: ")
for i in range(0, n):
    ele = int(input())
  
    input_arr.append(ele)

search_key = int(input("Enter element to search: "))

result = rotated_search(input_arr, search_key)
print("Value present at index", result)
