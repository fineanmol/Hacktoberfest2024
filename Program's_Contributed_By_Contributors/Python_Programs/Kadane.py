def maxSubarraySum(arr):
    res = arr[0]
  
    for i in range(len(arr)):
        currSum = 0
        for j in range(i, len(arr)):
            currSum = currSum + arr[j]

            res = max(res, currSum)
          
    return res

if __name__ == "__main__":
    arr = [2, 3, -8, 7, -1, 2, 3]
    print(maxSubarraySum(arr))
