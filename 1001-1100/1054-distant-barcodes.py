from typing import List

from collections import Counter
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        cnts = Counter(barcodes)
        cnts = [(k, v) for k, v in cnts.items()]
        best_k = None
        best_v = 0
        for k, v in cnts:
            if v > best_v:
                best_v = v
                best_k = k
        def filler():
            for _ in range(best_v):
                yield best_k
            for k, v in cnts:
                if k != best_k:
                    for _ in range(v):
                        yield k
        ans = [None] * len(barcodes)
        f = filler()
        '''
        0, 1, 2
        0, 2, 1

        0, 1, 2, 3
        0, 2, 1, 3
        2, 0, 3, 1
        '''
        i = 0
        for x in f:
            ans[i] = x
            i += 2
            if i >= len(ans):
                if len(ans) % 2 == 1:
                    i -= len(ans)
                else:
                    i -= len(ans) - 1
        return ans

print(Solution().rearrangeBarcodes([1,1,1,1,2,2,3,3]))
