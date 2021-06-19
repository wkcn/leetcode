class Solution:
    def numSquares(self, n: int) -> int:
        i = 1
        qs = []
        while i * i <= n:
            qs.append(i * i)
            i += 1
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for x in qs:
            for i in range(x, n + 1):
                dp[i] = min(dp[i], dp[i - x] + 1) 
        return dp[n]


print(Solution().numSquares(12))
