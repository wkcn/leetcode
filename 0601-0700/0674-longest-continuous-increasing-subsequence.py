from typing import List

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans = 0
        i = 0
        while i < len(nums):
            j = i + 1
            while j < len(nums) and nums[j - 1] < nums[j]:
                j += 1
            ans = max(ans, j - i)
            i = j
        return ans



assert Solution().findLengthOfLCIS([1, 3, 5, 4, 7]) == 3
