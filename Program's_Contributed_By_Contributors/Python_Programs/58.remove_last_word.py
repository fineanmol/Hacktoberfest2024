class Solution:
    def lengthOfLastWord(self, s: str) -> int:
         result=s.strip().split()[-1]
         print(len(result))
        
        

a=Solution()
a.lengthOfLastWord()