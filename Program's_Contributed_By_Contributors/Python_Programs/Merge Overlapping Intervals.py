
# Merge Overlapping Intervals

#Following Approch to solve the problem with the help of Stack.
'''
Sorting the intervals based on the increasing order of starting time.
Push the first interval into a stack.
For each interval do the following:
If the current interval does not overlap with the top of the stack then, push the current interval into the stack.
If the current interval overlap with the top of the stack then, update the stack top with the ending time of the current interval.
The end stack contains the merged intervals
'''

'''''
TC - O(n) SC O(n)

def MergeOverlapInterval(interval):

	interval.sort()

	stack = []

	stack.append(interval[0])

	for i in interval[1:]:

		if  stack[-1][0] <= i[0] <= stack[-1][-1]:

			stack[-1][-1] = max(stack[-1][-1],i[-1])
		else:

			stack.append(i)

	return stack
'''
#Following Approch to solve the problem with the help of indexing.

''''

Sort all intervals in increasing order of start time.
Traverse sorted intervals starting from the first interval, 
Do the following for every interval.
If the current interval is not the first interval and it overlaps with the previous interval,
then merge it with the previous interval. Keep doing it while the interval overlaps with the previous one.         
Otherwise, Add the current interval to the output list of intervals.

'''''

# TC - O(n) SC - O(1)

def MergeOverlapInterval(interval):

	interval.sort()
	index = 0 

	for i in range(1,len(interval)):

		if interval[index][1] >= interval[i][0] :

			interval[index][1] = max(interval[index][1],interval[i][1])
		else:

			index +=1

			interval[index] = interval[i]

	return interval[:index+1]


interval = [[5,8],[1,7],[4,8],[8,14],[12,7]]

res = MergeOverlapInterval(interval)

print(res)