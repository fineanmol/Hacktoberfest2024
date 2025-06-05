def binary_search(array, target):
    length = len(array)
    start = 0
    end = length - 1

    while start <= end:
        mid = start + (end - start)//2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return -1


if __name__ == "__main__":
    array = [1, 3, 4, 7, 12, 24, 36]
    print(f"Input array: {array}")
    print(f"Search result for value 7 is {binary_search(array, 7)}")
    print(f"Search result for value 13 is {binary_search(array, 13)}")
