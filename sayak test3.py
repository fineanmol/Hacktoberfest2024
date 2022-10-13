def findRanks(N, marks):
    temp=[]
    temp=sorted(marks)
    
    res=[N]
    
    for i in range(N):
        for j in range(N):
            if(temp[i]==marks[j]):
                if(i==N-1):
                  marks[j]="Gold Medal"
                  break
                elif(i==N-2):
                    marks[j]="Silver Medal"
                    break
                elif(i==N-3):
                    marks[j]="Bronze Medal"
                    break
                else:
                    marks[j]=(N-i)
                    break
    output = [str(x) for x in marks]
    st=""
    for pos in output:
        st+=pos+" "
    return st.strip()

N=int(input())
marks=[]
temp=input().split()
for i in range(N):
    marks.append(int(temp[i]))
    



print(findRanks(N, marks))