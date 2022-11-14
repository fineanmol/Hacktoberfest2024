def reversesearch(arr,key):
    low=0
    high=len(arr)-1
    while low<=high:
        
        mid=low+((high-low)//2)
        if arr[mid]==key:
            return mid
        elif arr[mid]>key:
            low=mid+1
        else:
 
arr=[6,5,4,3,2,1]
print(reversesearch(arr,4))

