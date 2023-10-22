
''' MAX SUBAARAY SUM USING KADANE'S ALGORITHM
    T.C. = O(n)
    S.C. = O(1) '''
    
    
def maxsubarraysum(arr):
  maxsumsofar = arr[0]
  maxsumendinghere = arr[0]
  for i in range(1, len(arr)):
    maxsumendinghere = max(maxsumendinghere+arr[i], arr[i])
    if maxsumsofar<maxsumendinghere:
      maxsumsofar = maxsumendinghere
  return maxsumsofar


if __name__ == '__main__':
    # arr = [-3, 2, -1, 4, -2]
    array = list(map(int, input().split()))
    print('Max subarray sum is: ', maxsubarraysum(array))
