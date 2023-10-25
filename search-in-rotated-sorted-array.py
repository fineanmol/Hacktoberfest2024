nums = [4,5,1,2,3]
k = -1
target = 3
for i in range(len(nums)):
    if nums[i] == target:
        k = i
print(k)
