class Solution(object):
    def minOperations(self, logs):
        """
        :type logs: List[str]
        :rtype: int
        """
        r = 0
        for log in logs:
            if log == '../':
                r = max(0, r - 1)
            elif log == './':
                pass
            else:
                r += 1
        return abs(r)
