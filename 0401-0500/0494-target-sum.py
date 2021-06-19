from typing import List

class Solution2:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # pos + neg = su, pos - neg = target
        # neg = (su - target) / 2 >= 0
        su = sum(nums)
        diff = su - target
        if diff % 2 or diff < 0:
            return 0
        neg = diff // 2
        dp = [0] * (neg + 1)
        dp[0] = 1
        for x in nums:
            for i in range(neg, x - 1, -1):
                dp[i] += dp[i - x]
        return dp[neg]

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        '''
        pos + neg = su, pos - neg = target
        2 * pos = su + target
        pos = (su + target) / 2
        '''
        su = sum(nums)
        su += target
        if su % 2:
            return 0
        su //= 2
        dp = [0] * (su + 1)
        dp[0] = 1
        for x in nums:
            for i in range(su, x - 1, -1):
                dp[i] += dp[i - x]
        return dp[su]


print(Solution().findTargetSumWays([1,1,1,1,1], 3))
