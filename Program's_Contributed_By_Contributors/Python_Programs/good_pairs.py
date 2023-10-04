# A program that return the number of valid pairs in an array

from collections import defaultdict

def numIdenticalPairs(nums):
    counts = defaultdict(int)
    # print(counts)
    ans = 0

    for num in nums:
        print(ans)
        ans += counts[num]
        print(counts)
        counts[num] += 1

    return ans

print(numIdenticalPairs([1, 2, 3, 1, 1, 4, 3]))