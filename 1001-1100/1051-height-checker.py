class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        sh = sorted(heights)
        return sum(a != b for a, b in zip(sh, heights))

class Solution(object):
    def heightChecker(self, nums):
        """
        :type heights: List[int]
        :rtype: int
        """
        M = 100
        N = M + 1
        cnts = [0] * N
        for x in nums:
            cnts[x] += 1
        i = 0
        ans = 0
        for x in nums:
            while cnts[i] == 0:
                i += 1
            # cnts[i] > 0
            if x != i:
                ans += 1
            cnts[i] -= 1
        return ans
