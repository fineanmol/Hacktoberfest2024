class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        triplet_count = 0
        final_list = set()

        for i in range(0, len(nums)-1):
            s = set()
            temp_list = []

            temp_list.append(nums[i])
            currk = 0 - nums[i]

            for j in range(i+1, len(nums)):
                if (currk - nums[j]) in s:
                    triplet_count += 1 

                    temp_list.append(nums[j])
                    temp_list.append(currk-nums[j])

                    final_list.add((tuple(sorted(temp_list))))
                    temp_list.pop(2)
                    temp_list.pop(1)
                s.add(nums[j])
        final_list = sorted(final_list)
        return([list(x) for x in final_list])
