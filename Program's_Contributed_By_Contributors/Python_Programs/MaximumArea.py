#Leetcode- coantainer with most water 
#You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

#Find two lines that together with the x-axis form a container, such that the container contains the most water.

#Return the maximum amount of water a container can store.

#Notice that you may not slant the container.


nums=[2,5,2]
i=0
j=len(nums)-1
maxvalue=0
while(i<j):
    h=min(nums[i],nums[j])
    print(h)
    w=abs(i-j)
    print(w)
    if(maxvalue<h*w):
        maxvalue=h*w
        print(maxvalue)
    if(nums[i]<nums[j]):
        i=i+1
    else:
        j=j-1
print(maxvalue)
