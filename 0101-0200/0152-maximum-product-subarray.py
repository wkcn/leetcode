from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        pos = 0
        neg = 0
        for x in nums:
            if x == 0:
                ans = max(ans, 0)
                pos = 0
                neg = 0
            elif x > 0:
                pos = max(x, pos * x)
                neg = neg * x
            else:
                # 注意min/max
                pos, neg = neg * x, min(pos * x, x)
            if pos != 0:
                ans = max(ans, pos)
            if neg != 0:
                ans = max(ans, neg)
        return ans

print(Solution().maxProduct([2,3,-2,4]))
print(Solution().maxProduct([-2, 0, -1]))
print(Solution().maxProduct([-3, -1, -1]))
