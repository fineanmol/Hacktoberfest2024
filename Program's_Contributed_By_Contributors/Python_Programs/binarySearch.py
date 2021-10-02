import random

# Binary Search


def binarySearch(sortedList, key, start, end):
    if start <= end:
        middleIndex = (start + end) // 2
        middleElement = sortedList[middleIndex]

        if middleElement == key:
            return middleIndex
        elif middleElement < key:
            location = binarySearch(sortedList, key, middleIndex + 1, end)
        else:
            location = binarySearch(sortedList, key, start, middleIndex - 1)

        return location

    return -1


myList = random.sample(range(0, 1000), 10)
target = int(input('Enter target: '))
location = binarySearch(myList, target, 0, len(myList) - 1)
print(f'Element found at index {location}.')


# Old version
# start,end
def binarySearch(key, start, end):
    # If start and end are adjacent elements, element does not exist
    if end == start + 1:
        return -1
    middleElementIndex = (start + end) // 2
    middleElement = myList[middleElementIndex]
    if key == middleElement:
        return middleElementIndex
    if key >= middleElement:
        start = middleElementIndex
        x = binarySearch(key, start, end)
    else:
        end = middleElementIndex
        x = binarySearch(key, start, end)
    return x


myList = [1, 2, 3, 4, 5, 12, 20, 30, 40, 45, 50, 70]
elementToBeFound = 5
print(f'List: {myList}')
x = binarySearch(elementToBeFound, 0, len(myList) - 1)
print(f'{elementToBeFound} found at index: {x}')
