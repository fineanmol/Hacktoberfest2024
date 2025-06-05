def magic_or_not(arr):
    total = sum(arr[0])
    diag1, diag2 = 0, 0
    for i in range(len(arr)):
        if sum(arr[i]) != total:
            return 'not magic'
        col = []
        for row in arr:
            col.append(row[i])
        if sum(col) != total:
            return 'not magic'
        # sum of diagonals
        diag1 += arr[i][i]
        diag2 += arr[i][len(arr)-1-i]
    if diag1 != total or diag2 != total:
        return 'not magic'
    return 'magic'


arr = []
for i in range(4):
    n = [int(i) for i in input().split()]
    arr.append(n)

print(magic_or_not(arr))
