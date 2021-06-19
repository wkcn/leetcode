from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for x in coins:
            for i in range(x, amount + 1):
                dp[i] += dp[i - x]
        return dp[amount]

print(Solution().change(5, [1,2,5]))
