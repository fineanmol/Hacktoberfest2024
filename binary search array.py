from pyarray import Array

def binsrch(Array, item):
        low = 0
        high = len(Array) - 1
        count=0
        while low <= high:
                count+=1
                mid = (high + low) // 2
                if Array[mid] == item:
                    print("Number found at", count,"iterations")
                    return mid
                elif item < Array[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
        print("Number not found. Iterations:",count)
        return None

mylist=[11,23,25,37,41,46,58,63,75]
myarray=Array(len(mylist))
for i in range(len(mylist)):
        myarray[i]=mylist[i]
myarray.traverse()
print("11:")
binsrch(myarray, 11)
print("43:")
binsrch(myarray, 43)
print("24:")
binsrch(myarray, 24)

