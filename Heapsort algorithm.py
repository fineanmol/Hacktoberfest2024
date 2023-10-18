def heapify(array, n, i):
    """
    Maintains the heap property of the binary heap.

    Args:
        array: The array to be heapified.
        n: The size of the array.
        i: The index of the parent node.
    """

    largest = i  # Initialize the largest element as the parent node
    left = 2 * i + 1  # Left child node
    right = 2 * i + 2  # Right child node

    # If left child node is larger than the parent node
    if left < n and array[left] > array[largest]:
        largest = left

    # If right child node is larger than the largest element
    if right < n and array[right] > array[largest]:
        largest = right

    # If largest is not the parent node, swap the parent node with the largest element
    if largest != i:
        array[i], array[largest] = array[largest], array[i]

        # Heapify the subtree rooted at the largest element
        heapify(array, n, largest)


def heapsort(array):
    """
    Sorts the given array using the Heapsort algorithm.

    Args:
        array: The array to be sorted.
    """

    n = len(array)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)

    # Sort the array
    for i in range(n - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        heapify(array, i, 0)


# Example usage:

array = [51, 13, 21, 11, 4]
heapsort(array)
print(array)
