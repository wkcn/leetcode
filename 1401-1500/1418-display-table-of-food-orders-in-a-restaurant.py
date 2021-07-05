from typing import List

from collections import defaultdict
class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        data = defaultdict(lambda : defaultdict(int))
        foods = set()
        for customer, tid, fid in orders:
            data[int(tid)][fid] += 1
            foods.add(fid)
        foods = list(foods)
        foods.sort()
        out = list()
        # head
        out.append(["Table"] + foods)
        for tid in sorted(data.keys()):
            out.append([str(tid)] + [str(data[tid][f]) for f in foods])
        return out


orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]

print(Solution().displayTable(orders))
