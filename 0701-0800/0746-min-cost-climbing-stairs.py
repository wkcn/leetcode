from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) < 2:
            return 0
        two = cost[0]
        one = cost[1]
        for i in range(2, len(cost)):
            old_one = one
            one = min(two, one) + cost[i]
            two = old_one
        return min(one, two)

print(Solution().minCostClimbingStairs([10,15,20]))
print(Solution().minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))
