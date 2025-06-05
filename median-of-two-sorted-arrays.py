import math
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums3=nums1+nums2
        nums3.sort()
        if len(nums3)%2==0:
            
            return float((nums3[len(nums3)/2]+nums3[len(nums3)/2-1]))/2
        else:
            return nums3[int(math.ceil(len(nums3)/2))]
