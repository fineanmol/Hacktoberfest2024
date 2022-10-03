def miniMaxsum(arr):
	p=arr[0]
	q=arr[1]
	r=arr[2]
	s=arr[3]
	t=arr[4]
	sum1=p+q+r+s
	sum2=q+r+s+t
	sum3=r+s+t+p
	sum4=s+t+p+q
	sum5=t+p+q+r
	sumlist=[]
	sumlist.append(sum1)
	sumlist.append(sum2)
	sumlist.append(sum3)
	sumlist.append(sum4)
	sumlist.append(sum5)
	sumlargest = max(sumlist)
	sumsmallest = min(sumlist)
	print(sumsmallest, sumlargest)
arr=[]
for i in range(0,5):
	inp = int(input('Enter number - '))
	arr.append(inp)
miniMaxsum(arr)

# Need to check highest and lowest sum of 4 out of 5 integer values of array
# --> Take p,q,r,s,t as elements of the array
# --> Take five variables as all posssible summing combos
# --> Append all in list
# --> Use max() and min() function of list to find required values
# --> Print the values

# Eg. arr=[1,3,5,7,9]:
# --> Elements of arr are assigned to p,q,r,s,t
# --> Sum1...Sum5 have all possible sum combinations of 4 of 5 values of arr.
# --> Append all in list 'sumlist'
# --> Use min() and max() function to find min and max sum values.
# --> Sum2 is largest (q+r+s+t --> 3+5+7+9 = 24)
# --> Sum1 is smallest (p+q+r+s --> 1+3+5+7 = 16)
