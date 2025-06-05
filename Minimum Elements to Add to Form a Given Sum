class Solution(object):
    def minElements(self, nums, limit, goal):
        d=abs(goal-sum(nums))
        c=d%limit
        if c==0:
            return d//limit
        else:
            return d//limit+1
            
        """
        :type nums: List[int]
        :type limit: int
        :type goal: int
        :rtype: int
        """
        
