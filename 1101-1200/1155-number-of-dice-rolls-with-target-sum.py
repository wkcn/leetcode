class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = [0] * (target + 1)
        # 避免越界
        for s in range(1, min(f + 1, target + 1)):
            dp[s] = 1
        for i in range(1, d):
            for t in range(target, 0, -1):
                su = 0
                for s in range(1, f + 1):
                    if t > s:  # 注意这里, 没有等号, 因为每次投色子, 数值必加1
                        su = (su + dp[t - s]) % (10 ** 9 + 7)
                dp[t] = su
        return dp[target]

print(Solution().numRollsToTarget(1, 6, 3))
print(Solution().numRollsToTarget(2, 6, 7))
print(Solution().numRollsToTarget(2, 5, 10))
print(Solution().numRollsToTarget(1, 2, 3))
print(Solution().numRollsToTarget(30, 30, 500))
