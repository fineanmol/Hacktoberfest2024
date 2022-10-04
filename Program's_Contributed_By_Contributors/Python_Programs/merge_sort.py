def merge(a):
    if len(a)>1:
        mid=(len(a))//2
        l=a[:mid]
        r=a[mid:]
        merge(l)
        merge(r)
        i=j=k=0
        while i<len(l) and j<len(r):
            if l[i]<r[j]:
                a[k]=l[i]
                i+=1
            else:
                a[k]=r[j]
                j+=1
            k+=1
        while i<len(l):
            a[k]=l[i]
            i+=1
            k+=1
        while j<len(r):
            a[k]=r[j]
            j+=1
            k+=1
def print_sortedarray(a):
    for i in range(len(a)):
        print(a[i],end=" ")
a=[5,6,8,0,3,4,21,1]
merge(a)
print_sortedarray(a)
