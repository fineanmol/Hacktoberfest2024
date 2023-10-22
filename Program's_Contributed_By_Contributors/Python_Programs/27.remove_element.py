class Solution:
    def removeElement(self, nums, val):
          count=0
          for i in range(len(nums)):
               if nums[i]!=val:
                    count+=1
               
          print(count)

a=Solution()
a.removeElement([3,2,2,3],3)
        
nums[1,2,3,4,5]=0