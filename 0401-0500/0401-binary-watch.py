import itertools

class Solution(object):
    def readBinaryWatch(self, turnedOn):
        """
        :type turnedOn: int
        :rtype: List[str]
        """
        '''
        up: 4
        down: 3
        '''
        bs = [[] for _ in range(7)]
        bs[0].append(0)
        num1s = [0]
        for i in range(1, 2 ** 6):
            d = num1s[i >> 1] + (i & 1)
            num1s.append(d)
            bs[d].append(i)
        ans = []
        for left in range(min(turnedOn, 4) + 1):
            right = turnedOn - left
            if right <= 6:
                for h, m in itertools.product(filter(lambda x: x<=11, bs[left]),
                                              filter(lambda x: x<=59, bs[right])):
                    ans.append('%d:%02d' % (h, m))
        return ans
            

print(Solution().readBinaryWatch(1))
