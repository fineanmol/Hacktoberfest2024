#merge sort using python



def m_sort(a):
 for i in 
range(len(a)):
 if i>1:
 
mid=len(a)//2
 
l_half=a[:mid]
r_half=a[mid:]
m_sort(l_half)
m_sort(r_half)
i=j=k=0
while i<len(l_half) and j<len(r_half):
 if l_half[i]<r_half[j]:
 
a[k]=l_half[i]
 i+=1
 else:
 
a[k]=r_half[j]
 j+=1
 k+=1
while 
i<len(l_half):
 
a[k]=l_half[i]
 i+=1
 k+=1
 while 
j<len(r_half):
  a[k]=r_half[j]
  j+=1
  k+=1
print("Enter elements into list:")
a=[int(x) for x in input().split()]
m_sort(a)
print(a)

#output:
 # enter elements into list:
 # 8 4 10 2 7 1
 # [1 2 4 7 8 10]
  
  
