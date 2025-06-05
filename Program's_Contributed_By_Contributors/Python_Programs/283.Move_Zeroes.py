nums=[45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648]
change=0
for i in range(len(nums)):
     for j in range(i+1,len(nums)):
          if nums[i]==0 < nums[j]:
               change=nums[i]
               nums[i]=nums[j]
               nums[j]=change
print(nums)
