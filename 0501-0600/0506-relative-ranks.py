class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        gs = ["Gold Medal","Silver Medal","Bronze Medal"]
        def name(i):
            if i < 3:
                return gs[i]
            return str(i + 1)
        idx = list(range(len(score)))
        idx.sort(key=lambda i: score[i], reverse=True)
        ans = [None for _ in range(len(score))]
        for j, i in enumerate(idx):
            ans[i] = name(j)
        return ans
