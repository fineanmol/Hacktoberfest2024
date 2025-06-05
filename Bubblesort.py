from pyarray import Array
def bubble(Array):
    n=len(Array)
    count=0
    for i in range(n-1):
        for j in range(n-1-i):
          if Array[j]>Array[j+1]:
            tmp=Array[j]
            Array[j]=Array[j+1]
            Array[j+1]=tmp
#            count=1
#       if count==0:
#           break

##LEC8 CONT...            
myarray=Array(16)
#lst=[11,23,5,37,41,0,100,56,14,6,12,46,58,63,75,3]
lst=[1,2,16,15,14,13,12,11,10,9,8,7,6,5,4,3]
c=0
for i in range(16):
      myarray[i]=lst[c]
      c+=1

print("BEFORE BUBBLE SORT IMPLEMENTATION")
myarray.traverse()
bubble(myarray)
print("AFTER IMPLEMENTATION")
myarray.traverse()

