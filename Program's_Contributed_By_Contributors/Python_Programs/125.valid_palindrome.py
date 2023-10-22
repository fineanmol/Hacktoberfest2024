class Solution:
    def isPalindrome(self, s: str) -> bool:
        loop=list(s.lower())
        for i in range(-1,-len(s),-1):
             print(loop[i],end='')
             
               
             
   
a=Solution()
a.isPalindrome("A man, a plan, a canal:Panama")