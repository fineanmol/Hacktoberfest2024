class Solution(object):
    # def coinChange(self, coins, amount):
    #     """
    #     :type coins: List[int]
    #     :type amount: int
    #     :rtype: int
    #     """
    #     # Top-down dp
    #     if amount < 1:
    #         return 0
    #     return self.coinChange_helper(coins, amount, [0] * (amount + 1))

    # def coinChange_helper(self, coins, amount, count):
    #     if amount < 0:
    #         return -1
    #     if amount == 0:
    #         return 0
    #     if count[amount - 1] != 0:
    #         return count[amount - 1]
    #     min_count = 1000000000
    #     for coin in coins:
    #         res = self.coinChange_helper(coins, amount - coin, count)
    #         if res >= 0 and res < min_count:
    #             min_count = 1 + res
    #     if min_count == 1000000000:
    #         count[amount - 1] = -1
    #     else:
    #         count[amount - 1] = min_count
    #     return count[amount - 1]

    def coinChange(self, coins, amount):
        # bottom-up dp
        if amount == 0:
            return 0
        if coins is None or len(coins) == 0:
            return -1
        coins.sort()
        dp = [1000000000] * (amount + 1)
        for i in range(1, amount + 1):
            for coin in coins:
                if i == coin:
                    dp[i] = 1
                    break
                elif i > coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        if dp[amount] == 1000000000:
            return -1
        return dp[amount]
