class Solution:
    def calPoints(self, ops: List[str]) -> int:
        li = []
        for c in ops:
            if c == '+':
                li.append(li[-1] + li[-2])
            elif c == 'D':
                li.append(li[-1] * 2)
            elif c == 'C':
                li.pop()
            else:
                li.append(int(c))
        return sum(li)
