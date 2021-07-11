from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        rob = nums[0]
        norob = 0
        for i in range(1, len(nums)):
            new_norob = max(norob, rob)
            rob = norob + nums[i]
            norob = new_norob
        return max(rob, norob)

# 定义好状态: 是到第i天(不管第i天有没有盗窃)的最大金额
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) <= 2:
            return max(nums)
        two, one = nums[0], max(nums[0:2])
        for i in range(2, len(nums)):
            old_one = one
            # 注意
            one = max(two + nums[i], one)
            two = old_one
        return max(one, two)

print(Solution().rob([1,2,3,1]))
print(Solution().rob([2,7,9,3,1]))
print(Solution().rob([2,1,1,2]))
print(Solution().rob([1,3,1,3,100]))
