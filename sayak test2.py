def findRanks(N, marks):
    temp=[]
    for i in range(N):
        temp[i]=marks[i]
    temp.sort(reverse=True)
    result=[N]
    
    for i in range(N):
        for j in range(N):
            if(temp[i]==marks[j]):
                if(i==0):
                    result[j]="Gold Medal"
                    break
                elif(i==1):
                    result[j]="Silver Medal"
                    break
                elif(i==2):
                    result[j]="Bronze Medal"
                    break
                else:
                    result[j]=(i+1)
                    break
    str=""
    for pos in result:
        str+=pos+" "
    print(str)
    return str

N=int(input())
marks=[]
temp=input().split()
for i in range(N):
    marks.append(int(temp[i]))
    



print(findRanks(N, marks))