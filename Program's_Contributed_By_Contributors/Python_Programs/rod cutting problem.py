# cut with max price result

def rodcutprob(w,wt,n,p):
    dp=[[-1 for x in range(w+1)] for x in range(n+1)]
    for i in range(n+1):
        for j in range(w+1):
            #print(i)
            if i==0:
                dp[i][j] = 0
            elif j == 0:
                dp[i][j] = 0
            elif wt[i-1] > j:
                dp[i][j] = dp[i-1][j] 
            else:
                #print(i,p[7])
                #print(p[i-1])#,i,j-wt[i-1],wt[i-1],j)
                                                        #change
                dp[i][j] = max(dp[i-1][j], p[i-1] + dp[i][j-wt[i-1]])
                
    return dp[n][w]

l=[1,2,3,4,5,6,7,8]
p=[1,5,8,9,10,17,17,20]
#w=8
#wt=[5,2,3]
#n=len(wt)
#n=5
n=8
w=8
wt=l
print(rodcutprob(w,wt,n,p))