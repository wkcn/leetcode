class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        cnts = collections.Counter((A + ' ' + B).split(' '))
        ps = filter(lambda x: x[1] == 1, cnts.items())
        return list(p[0] for p in ps)
