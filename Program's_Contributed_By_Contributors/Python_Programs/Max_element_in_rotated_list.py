n = int(input())
arr = list(map(int, input().split()))

low = 1
high = len(arr) - 1
val = arr[0]

while(low<=high):
    mid = (low + high) // 2;
    if(val > arr[mid]):
        high = mid - 1
    elif(val < arr[mid]):
        low = mid + 1
        val = arr[mid]

print(val)
