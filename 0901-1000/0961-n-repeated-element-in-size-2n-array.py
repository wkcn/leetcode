class Solution(object):
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        se = set()
        for x in A:
            if x in se:
                return x
            se.add(x)
        return 0
