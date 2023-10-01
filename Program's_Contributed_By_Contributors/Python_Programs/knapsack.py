w=[int(x) for x in input("enter weights: ").split()]
v=[int(x) for x in input("enter values: ").split()]
bag=int(input("enter bag capacity: "))
n=len(v)
def knapSack(bag,w,v,n):
    if n==0 or bag==0:
        return 0
    if (w[n-1] > bag):
        return knapSack(bag, w, v, n-1)
    else:
        return max(v[n-1] + knapSack(bag-w[n-1], w, v, n-1),knapSack(bag, w, v, n-1))
knapSack(bag,w,v,n)
# knapsack problem by ayushtripathi12103634