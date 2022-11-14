array = [14, 4 , 56, 2, 100, 97]
l = len(array)
for i in range(l-1):
    temp = i
    for j in range(i+1, l):
        if array[j] < array[temp]:
            temp = j
    array[i], array[temp] = array[temp], array[i]

print(array)
