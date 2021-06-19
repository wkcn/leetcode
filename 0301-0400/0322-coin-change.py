from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 完全背包
        # 最少值
        dp = [None] * (amount + 1)
        dp[0] = 0
        for x in coins:
            for i in range(x, amount + 1):
                if dp[i - x] is not None:
                    if dp[i] is None:
                        dp[i] = dp[i - x] + 1
                    else:
                        dp[i] = min(dp[i], dp[i - x] + 1)
        if dp[amount] is None:
            return -1
        return dp[amount]

print(Solution().coinChange([1, 2, 5], 11))
print(Solution().coinChange([2], 3))
