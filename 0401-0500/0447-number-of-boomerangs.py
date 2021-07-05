from typing import List


from collections import defaultdict
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for i, p1 in enumerate(points):
            cnts = defaultdict(int)
            for p2 in points:
                x2 = (p1[0] - p2[0]) ** 2
                y2 = (p1[1] - p2[1]) ** 2
                z2 = x2 + y2
                cnts[z2] += 1
            for v in cnts.values():
                ans += v * (v - 1)
        return ans

print(Solution().numberOfBoomerangs([[0,0],[1,0],[2,0]]))
