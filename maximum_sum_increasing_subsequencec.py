# Naive Approach to find maximum sum increasing subsequence Using Recursion
import sys
 
 
# Function to find the maximum sum of increasing subsequence
def maximumSubsequence(arr, i=0, prev=-sys.maxsize, total=0):
 
    # base case: nothing is remaining
    if i == len(arr):
        return total
 
    # case 1: exclude the current element and process the
    # remaining elements
    excl = maximumSubsequence(arr, i + 1, prev, total)
 
    # case 2: include the current element if it is greater
    # than the previous element
    incl = total
    if arr[i] > prev:
        incl = maximumSubsequence(arr, i + 1, arr[i], total + arr[i])
 
    # return the maximum of the above two choices
    return max(incl, excl)
 
 
if __name__ == '__main__':
 
    arr = [1, 8, 3, 12, 2, 10, 4, 14, 2, 6, 6, 13, 2, 10]
    print(maximumSubsequence(arr))
