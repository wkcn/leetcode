from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        '''
        注意, 这里问的是排列数
        '''
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(1, target + 1):
            for x in nums:
                if i >= x:
                    dp[i] += dp[i - x]
        return dp[target]

print(Solution().combinationSum4([1, 2, 3], 4))
