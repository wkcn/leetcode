from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans = None
        cnt = 0
        for x in nums:
            if cnt == 0:
                ans = x
                cnt += 1
            elif ans == x:
                cnt += 1
            else:
                cnt -= 1
        if cnt == 0:
            return -1
        if len(list(filter(lambda x: x == ans, nums))) > len(nums) / 2:
            return ans
        return -1

print(Solution().majorityElement([1,2,5,9,5,9,5,5,5]))
print(Solution().majorityElement([1,2,3]))
