# DP 好题
from typing import List

def lower_bound(a, target, lo=None, hi=None):
    if lo is None:
        lo = 0
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = lo + ((hi - lo) >> 1)
        if a[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    return lo

class Solution:
    def canCross2(self, stones: List[int]) -> bool:
        # 状态: (当前位置, 已经跳了多少步)
        n = len(stones)
        buf = dict()
        def go(i, k):
            if i == n - 1:
                return True
            key = (i, k)
            value = buf.get(key, None)
            if value is not None:
                return value
            '''
            当前在位置stones[i], 并且上一次跳了k步
            '''
            for step in range(k - 1, k + 2):
                if step <= 0:
                    continue
                # 注意是stones[i] + step
                to = stones[i] + step
                p = lower_bound(stones, to, lo=i + 1)
                if p != n and stones[p] == to:
                    # found
                    if go(p, step):
                        buf[key] = True
                        return True
            buf[key] = False
            return False
        if len(stones) <= 1:
            return True
        if stones[1] != 1:
            return False
        return go(1, 1)

    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        '''
        dp[i, k] = dp[j, k - 1] or dp[j, k] or dp[j, k + 1]
        stones[i] - stones[j] = k
        '''
        # 当前位置是i, 上一次跳跃的步数是k, 有k <= i
        for i in range(n - 1):
            if stones[i + 1] - stones[i] > i + 1:
                return False
        dp = [[False for _ in range(n)] for _ in range(n)]
        dp[0][0] = True
        for i in range(1, n):
            # 注意这里是逆序, 使得k <= j + 1时能直接结束循环
            for j in range(i - 1, -1, -1):
                k = stones[i] - stones[j]
                # 注意这里
                if k > j + 1:
                    break
                dp[i][k] |= dp[j][k - 1] or dp[j][k] or dp[j][k + 1] 
        return any(dp[-1])


stones = [0, 1, 3, 5, 6, 8, 12, 17]
assert Solution().canCross(stones) == True

stones = [0, 1, 2, 3, 4, 8, 9, 11]
assert Solution().canCross(stones) == False
