class Solution:
    def minJumps(self, arr, n):
        jump=0
        h=0
        m=0
        '''if arr[h]==0:
            return(-1)'''
        for i in range (n):
            
            m=max(m,i+arr[i])
            
            if m>=n-1:
                jump+=1
                return(jump)
            if h==i:
                h=m
                jump+=1
            if arr[i]==0 and m<=i:
                break    
        if h>=n-1:
            return(jump)
        
        return(-1)
            
           


if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.minJumps(Arr,n)
        print(ans)

