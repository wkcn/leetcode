from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        ans = [[arr[0], arr[1]]]
        mi = arr[1] - arr[0] 
        for i in range(2, len(arr)):
            p = [arr[i - 1], arr[i]]
            d = p[1] - p[0]
            if d < mi:
                ans = [p]
                mi = d
            elif d == mi:
                ans.append(p)
        return ans

arr = [4, 2, 1, 3]
print(Solution().minimumAbsDifference(arr))
