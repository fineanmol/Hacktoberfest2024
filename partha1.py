

def sort2darray(arr):
   for i in range(len(arr)):
       arr[i].sort()
   return arr
    


m=int(input())
n=int(input())
arr=[]
for i in range(m):
    a =[]
    for j in range(n):
        a.append(int(input()))
    arr.append(a)
result=sort2darray(arr)
print(result)