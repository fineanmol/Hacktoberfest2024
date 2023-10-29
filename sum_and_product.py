# sum and product problem from codeforces solved 
t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    q=int(input())
    ans=[]
    c=set(a)
    b=[]
    for z in c:
        if a.count(z)>=3:
            b.append(z)
            b.append(z)
            b.append(z)
        elif a.count(z)>=2:
            b.append(z)
            b.append(z)
        else:
            b.append(z)
    m=len(b)
    for j in range(q):
        target=list(map(int,input().split()))
        huge=[]
        for k in range(m):
            for l in range(k+1,m):
                sum=b[k]+b[l]
                prod=b[k]*b[l]
                huge.append([sum,prod])
        if target in huge:
            ans.append(huge.count(target))
        else:
            ans.append(0)
    print(*ans)
