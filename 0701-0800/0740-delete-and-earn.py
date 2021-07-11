from typing import List

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnts = [0] * 10001
        for x in nums:
            cnts[x] += 1
        two = one = 0
        for i in range(1, 10001):
            new_one = max(one, two + cnts[i] * i)
            two = one
            one = new_one
        return max(one, two)

print(Solution().deleteAndEarn([2,2,3,3,3,4]))
