from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 0/1 背包
        su = sum(nums)
        if su % 2:
            return False
        half = su // 2
        dp = [False] * (half + 1)
        dp[0] = True
        for x in nums:
            for i in range(half, x - 1, -1):
                if dp[i - x]:
                    dp[i] = True

        return dp[half]

print(Solution().canPartition([1, 5, 11, 5]))
print(Solution().canPartition([1, 2, 3, 5]))
