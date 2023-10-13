#
# Python3 Version
# 0-1 Knapsack Problem using DP
#

def main():
    weights = [10, 20, 30]
    vals = [60, 100, 120]
    print(solve(3, 50, weights, vals))

def solve(item_num, max_weight, weights, vals):

    dp = [[0 for x in range(max_weight+1)] for y in range(item_num+1)]

    for i in range(1,item_num+1):
        for j in range(1,max_weight+1):
            if j-weights[i-1] >= 0:
                dp[i][j] = max(dp[i-1][j-weights[i-1]]+vals[i-1], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]

    return dp[item_num][max_weight]
''' Knapsack Problem '''

def knapSack(weights, values, capacityWeight, n):
    if n == 0 or capacityWeight == 0 : 
        return 0
   
    if (weights[n-1] > capacityWeight): 
        return knapSack( weights , values ,capacityWeight, n-1) 
  
    else: 
        return max(values[n-1] + knapSack(weights , values ,capacityWeight-weights[n-1], n-1), 
                   knapSack(weights , values,capacityWeight , n-1))
                  
if __name__ == '__main__':
  main()          
  print('='*60)
  values = [60, 100, 120] 
  weights = [10, 20, 30] 
  capacityWeight = 50
  n = len(values) 
  print(knapSack(weights , values , capacityWeight , n))
