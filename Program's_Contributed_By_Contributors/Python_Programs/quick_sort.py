def partition(strt,end,a):
    pvt_idx=strt
    pvt=a[pvt_idx]
    while strt<end:
        while strt<len(a) and a[strt]<=pvt:
            strt+=1
        while a[end]>pvt:
            end-=1
        if strt<end:
            a[end],a[strt]=a[strt],a[end]
    a[end],a[pvt_idx]=a[pvt_idx],a[end]
    return end
def quick(strt,end,a):
    if strt<end:
        p=partition(strt,end,a)
        quick(strt,p-1,a)
        quick(p+1,end,a)

a=[5,6,8,0,3,4,21,1]
quick(0,len(a)-1,a)
for i in range(len(a)):
    print(a[i],end=" ")
