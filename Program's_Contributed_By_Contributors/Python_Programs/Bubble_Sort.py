def bubble(a):
    swapped = True
    while swapped:
        swapped = False
        # Loop to iterate
        for i in range(len(a) - 1):
            if a[i] > a[i + 1]:
                swapped = True
                # Swap the numbers
                a[i], a[i + 1] = a[i + 1], a[i]
    return a
a = [55,89,23,12,5]
print(bubble(a))