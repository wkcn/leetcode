class Solution(object):
    def minSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        su = sum(nums)
        idx = list(range(len(nums)))
        idx.sort(key=lambda i: nums[i], reverse=True)
        se_su = 0
        se_idx = []
        for i in idx:
            se_idx.append(i)
            se_su += nums[i]
            if se_su > su - se_su:
                break
        return [nums[i] for i in se_idx]


if __name__ == '__main__':
    a = [4, 3, 10, 9, 8]
    print(Solution().minSubsequence(a))
