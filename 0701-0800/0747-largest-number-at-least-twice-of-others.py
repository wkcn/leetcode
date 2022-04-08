class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        i = max(enumerate(nums), key=lambda x: x[1])[0]
        if all(map(lambda x: nums[i] >= x * 2, nums[:i] + nums[i+1:])):
            return i
        return -1
