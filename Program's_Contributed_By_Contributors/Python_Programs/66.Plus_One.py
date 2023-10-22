class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        hi=''
        for i in range(len(digits)):
            hi = hi+str(digits[i])

        result=str(int(hi)+1)
        ans=[]
        for i in result:
            ans.append(int(i))

        return ans

a=Solution()
a.plusOne([1,2,3])