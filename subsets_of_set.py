lis=[1,2,3,4]
subsets=[]

for i in range(len(lis)+1):
    if i==0:
        subsets.append([])
    elif i==1:
        for j in range(len(lis)):
            subsets.append([lis[j]])
    elif i>1:
        for j in range(len(lis)-i+1):
            subset=[]
            for k in range(j,j+i-1):
                subset.append(lis[k])
            for k in range(j+i-1,len(lis)):
                subset1=[]
                subset1.extend(subset)
                subset1.append(lis[k])
                subsets.append(subset1)
                
print(subsets)
