from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        return max(self.rob_impl(nums[:-1]), self.rob_impl(nums[1:]))
    def rob_impl(self, nums):
        if len(nums) <= 2:
            return max(nums)
        one = max(nums[:2])
        two = nums[0]
        for x in nums[2:]:
            old_one = one
            one = max(two + x, one)
            two = old_one
        return one


assert Solution().rob([2, 3, 2]) == 3
assert Solution().rob([]) == 0
assert Solution().rob([2]) == 2
assert Solution().rob([2, 3]) == 3
assert Solution().rob([1, 2, 3, 1]) == 4
