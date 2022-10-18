#Implementing 0/1 Knapsack problem using Dynamic Programming.
#logic:
#Given some items, pack the knapsack to get the maximum total profit. Each item has some 
#Weight and some profit. Total weight that we can carry is no more than some fixed number W.


def show(W,n,wt,V):
 i=n
 w=W
 print("The items entered into the knapsack are:")
 while i>0 and w>0:
 if V[i][w]!=V[i-1][w]:
 print(i,"item with weight",wt[i])
 w=w-wt[i]
 i=i-1
 else:
 i=i-1
 print("Weight taken into the sack is",W-w,"with having maximum value",V[n][W])
def knapsack(W,n,val,wt):
 V=[[0 for j in range(W+2)] for i in range(n+2)]
 for i in range(n+1):
 for w in range(W+1):
 if wt[i]<=w:
 V[i][w]=max(V[i-1][w],(val[i]+V[i-1][w-wt[i]]))
 else:
 V[i][w]=V[i-1][w]
 print(V[i][w],end="\t")
 print("\n")
 show(W,n,wt,V)
n=int(input("Enter the items:"))
val=[0 for i in range(0,n+1,1)]
wt=[0 for i in range(0,n+1,1)]
print("Enter the values of products:")
for i in range(1,n+1,1):
 temp=int(input())
val[i]=temp
print("Enter the weights of products:")
for i in range(1,n+1,1):
 temp=int(input())
 wt[i]=temp
W=int(input("Enter the maximum capacity of knapsack:"))
knapsack(W,n,val,wt)
