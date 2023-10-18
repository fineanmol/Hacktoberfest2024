class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        import math
        if n>0:
            e = log(n,3)
            x = round(e,1)
            if(pow(3,x)==n):
                return True 
            else:
                return False
        
