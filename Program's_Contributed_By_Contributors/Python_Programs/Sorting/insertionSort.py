array = [14, 4 , 56, 2, 100, 97]
l = len(array)

for i in range(1, l):
    j = i
    while j>0 and array[j] < array[j-1]:
        array[j], array[j-1] = array[j-1], array[j]
        j -= 1

print(array)