from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [None] * (rowIndex + 1)
        ans[0] = 1
        for r in range(1, rowIndex + 1):
            ans[r - 1] = 1
            for c in range(r - 1, 0, -1):
                ans[c] += ans[c - 1]
        ans[-1] = 1
        return ans

for i in range(0, 10):
    print(i, Solution().getRow(i))
