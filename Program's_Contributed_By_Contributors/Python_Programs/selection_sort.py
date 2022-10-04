def selection(a,n):
    for i in range(n):
        for j in range(i+1,n):
            if a[i]>a[j]:
                a[i],a[j]=a[j],a[i]
    
    for i in range(n):
        print(a[i],end=" ")
    return 
a=[5,6,7,9,3,4,2]
n=len(a)
selection(a,n)
