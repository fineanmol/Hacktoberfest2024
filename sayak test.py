
def minDiff(input1,input2,input3):
    diff = +2147483647
    
    
    input2.sort()
  
    for i in range(input1-input3+1):
        temp=input2[i+input3-1] - input2[i]
        if(temp<diff):
            diff=temp
            res=[]
            for j in range(i,i+input3):
                res.append(input2[j])
                
  
    if(input3==1):
        li=[]
        li.append(input2[input1-1])
        return li
    else:
        return res

 
arr= [950,477,55,602,881,302,859,438,551,382]
n =10
k = 1
  
print(minDiff(n,arr, k))
