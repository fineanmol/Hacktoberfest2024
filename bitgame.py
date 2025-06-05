class Solution:
    def swapBitGame (self,N):
        # code here 
        b=bin(N)[2:]
        o=b.count('1')
        if o%2==0:
            return 2
        else:
            return 1
