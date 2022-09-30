#taking input
arr = list(map(str, input("enter array").split()))

#element to search 
element = input("enter element to search")

#implementing binary search
left = 0
right = len(arr)-1

check = 0

while left<right:
    mid = (left+right)//2
    
    if arr[mid] == element: #if element is found
        check = 1
        break
    elif arr[mid] > element: # if element is less than arr[mid]
        right = mid - 1
    else:                    # if element is greater than arr[mid]
        left = mid + 1
        
print("element found") if check else print("element not found") #print found if check == 1 else not found