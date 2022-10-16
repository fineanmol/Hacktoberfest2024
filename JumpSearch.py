'''Jump Search Algorithm
Step-1:Start from the leftmost element of arr[] and compare the element with blocks of length of n^(1/2)
Step-2:If x matches with an element, return the index.
Step-3:If x doesn’t match with any of elements, return -1.'''
def jumpSearch(arr, x, n):
    s = n**0.5
    p = 0
    while arr[int(min(s, n)-1)] < x:
        p = s
        s += (n**0.5)
        if p >= n:
            return -1
    while arr[int(p)] < x:
        p += 1
        if p == min(s, n):
            return -1
    if arr[int(p)] == x:
        return p

    return -1


arr = [0, 1, 2, 3, 5, 41, 446, 496, 646, 4964, 9441]
x = int(input("Element ? "))
n = len(arr)

index = jumpSearch(arr, x, n)

if int(index) != -1:
    print("Index of element is ", int(index))
else:
    print("Element not found")
