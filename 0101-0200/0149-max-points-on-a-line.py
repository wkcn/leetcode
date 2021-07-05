from typing import List
from collections import defaultdict
import math

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        best = 0
        for i in range(len(points)):
            x1, y1 = points[i]
            # 记录一条直线出现的次数
            cnts = defaultdict(int)
            for j in range(i + 1, len(points)):
                x2, y2 = points[j]
                v3 = (y2 - y1, x1 - x2, x2 * y1 - x1 * y2)
                # 记录第一个非零元素的下标
                nzi = None
                for k, v in enumerate(v3):
                    if v != 0:
                        nzi = k
                        break
                if nzi is not None:
                    # 三元组里存在非零的元素
                    # g为三元组中非零元素的最大公约数
                    g = math.gcd(*filter(lambda x: x != 0, v3))
                    if v3[nzi] < 0:
                        # 让三元组的第一个非零元素为正数
                        g = -g
                    # 进行约分
                    v3 = tuple(map(lambda x: x // g, v3))
                # 进行计数
                cnts[v3] += 1
                best = max(best, cnts[v3])
        return best + 1


if __name__ == '__main__':
    points = [[1,1],[2,2],[3,3]]
    print(Solution().maxPoints(points))
