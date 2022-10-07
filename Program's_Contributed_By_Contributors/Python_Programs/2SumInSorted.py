arr=[1,2,3,4,5,6]
k=10
low=0
high=len(arr)-1
while low<high:
    s=arr[low]+arr[high]
    if s==k:
        print(arr[low],arr[high])
        break
    else:
        if s<k:
            low+=1
        else:
            high-=1
