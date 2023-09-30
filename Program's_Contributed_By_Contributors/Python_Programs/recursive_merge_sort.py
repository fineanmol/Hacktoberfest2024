def mergeSort(li):
    if len(li) <= 1:
        return li
    
    x = li[-1]
    left = []
    right = []

    for i in range(len(li) - 1):
        if li[i] <= x:
            left.append(li[i])
        else:
            right.append(li[i])

    return mergeSort(left) + [x] + mergeSort(right)