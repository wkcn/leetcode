from typing import List

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                # swap nums[i] and nums[nums[i] - 1]
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return [nums[i], i + 1]

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        v = 0
        for i in range(1, n + 1):
            v ^= i
        for i in range(0, n):
            v ^= nums[i]
        # v = ans[0] ^ ans[1]
        li = v & (-v)
        # 根据li分为0组和1组
        s = 0
        for x in nums:
            if x & li:
                s ^= x
        for x in range(1, n + 1):
            if x & li:
                s ^= x
        for x in nums:
            if x == s:
                return [s, s ^ v]
        return [s ^ v, s]

print(Solution().findErrorNums([1,2,2,4]))
print(Solution().findErrorNums([1,1]))
print(Solution().findErrorNums([3,2,2]))
print(Solution().findErrorNums([8,7,3,5,3,6,1,4]))
