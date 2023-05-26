#
#

def maxSlidingWindow(nums, k):
    q = []
    out = []

    for i in range(0, len(nums)):
        q.append(nums[i])

        if len(q) > 3: 
            q.pop(0)

        if len(q) == 3:
            out.append(max( q ))

    return out



nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3

print (maxSlidingWindow(nums, k))