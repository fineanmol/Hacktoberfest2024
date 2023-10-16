
def selection_sort_inFront(a):
    n = len(a)
    for i in range(n-1):
        position = i
        minimum = a[i]
        for j in range(i+1, n):
            if a[j] < minimum:
                position = j
                minimum = a[j]
        a[position] = a[i]
        a[i]=minimum
        print(a)
    
numbers = "44 55 12 42 94 18 6 67"
a = [int(i) for i in numbers.split()]

print(selection_sort_inFront(a))