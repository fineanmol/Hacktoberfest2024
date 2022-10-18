#kadene algo is use for get muximum sum of subarray

# we can split this algo in 3 steps 

# step1 : sum = sum + arr[i]

# step2: update max,  maxi = max(sum,maxi)

# if sum less 0 update sum to 0

# step 3: if sum<0 : sum = 0

def maxSum(arr,n):
    sum = 0
    maxi = arr[0]
    for i in range(len(arr)):
        sum = sum + arr[i]

        maxi = max(sum,maxi)

        if sum < 0:
            sum = 0
    return maxi

if __name__ == "__main__":
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    print(maxSum(arr,n))
# input : 1 2 5 6 8 -4 5
