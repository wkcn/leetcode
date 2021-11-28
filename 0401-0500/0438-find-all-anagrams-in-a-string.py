class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnts = Counter(p)
        cur = Counter(s[:len(p)])
        ans = []
        if cur == cnts:
            ans.append(0)
        for i in range(len(p), len(s)):
            cur[s[i]] += 1
            c = s[i - len(p)]
            cur[c] -= 1
            if cur[c] == 0:
                cur.pop(c)
            if cur == cnts:
                ans.append(i - len(p) + 1)
        return ans
