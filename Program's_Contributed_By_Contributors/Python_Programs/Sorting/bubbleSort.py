array = [14, 4 , 56, 2, 100, 97]
l = len(array)

for i in range(l-1):
    for j in range(l-i-1):
        if array[j] > array[j+1]:
            array[j], array[j+1] = array[j+1], array[j]

print(array)