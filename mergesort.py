'''merge has complexity of (6n*log n base 2) + 6n  big Oh of nlog n it better than insertion sort for higher range
it sort by sorting sub parts of given array and then merge them'''


def merge(L,R):
	(ll,lr)=(len(L),len(R))
	(i,j,t)=(0,0,[])
	while i+j<ll+lr:
		if(i==ll):
			t.append(R[j])
			j=j+1
		elif j==lr:
			t.append(L[i])
			i=i+1
		elif L[i]<=R[j]:
			t.append(L[i])
			i=i+1
		elif R[j]<L[i]:
			t.append(R[j])
			j=j+1
	return t



def mergesort(arr,l,r):
	if r-l<=1:
		return arr[l:r]
	if r-l>1:
		mid=(r+l)//2
		L=mergesort(arr,l,mid)
		R=mergesort(arr,mid,r)
		return merge(L,R)

print("enter")
arr=list(map(int,input().split()))
pp=mergesort(arr,0,len(arr))
print(pp)
