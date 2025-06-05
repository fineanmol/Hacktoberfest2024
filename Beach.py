#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
def bea(Arr):

    
    
    
    if(len(Arr)==1):
        return Arr[0]
    
    Krr = []
    j=0
    max=0
    while(j < len(Arr)):
    
        if(len(Krr) == 0 or Arr[Krr[-1]] <= Arr[j]):
    
            Krr.append(j)
            j += 1
    
        else:
    
            tp=Krr[-1]
            Krr.pop()
    
            if not Krr:
                res = j
    
            else:
                res = j - Krr[-1] - 1
    
            maxtop=Arr[tp]*(res)
    
            if(max<maxtop):
                max=maxtop

    while Krr: 
    
        tp=Krr[-1]
        Krr.pop()
    
        if not Krr:
                res = j
    
        else:
            res = j - Krr[-1] - 1
    
        maxtop=Arr[tp]*(res)
    
        if(max<maxtop):
            max=maxtop

    return max

for _ in range(int(input())):
    n = int(input())
    v = list(map(int,input().split()))
    print(bea(v))


# In[ ]:




