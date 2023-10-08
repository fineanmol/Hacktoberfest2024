def binary_search_recursive(array, low, high, E):
    # Base Condition
    if high >= low:

        # First calculating the mid index
        mid = (high + low) // 2

        # If the element is present at the middle index, return the index as the answer.
        if array[mid] == E:
            return mid

        # If element is smaller than the middle element, then recursively checking the left sub array.
        elif array[mid] > E:
            return binary_search_recursive(array, low, mid - 1, E)

        # Else recursively checking the right sub array.
        else:
            return binary_search_recursive(array, mid + 1, high, E)

     # As the element is not present in the array, return -1.
    else:
        return -1


if __name__ == "__main__":
    array = [13, 110, 115, 120, 135, 140, 260]
    E = 115
    low = 0
    high = len(array) - 1

    index = binary_search_recursive(array, low, high, E)

    if index != -1:
        print(f"Element {E} is found in the array at index", str(index))
    else:
        print(f"Element {E} is not present in the array.")


