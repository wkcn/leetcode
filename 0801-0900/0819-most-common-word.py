from typing import List

from collections import Counter
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.lower()
        signs = set("!?',;.")
        for c in signs:
            paragraph = paragraph.replace(c, ' ')
        sp = paragraph.split()
        banned = set(banned)
        cnts = Counter(filter(lambda x: x not in banned, sp))
        ans = None
        maxv = 0
        for k, v in cnts.items():
            if v > maxv:
                ans = k
                maxv = v
        return ans

paragraph = 'Bob hit a ball, the hit BALL flew far after it was hit.'
banned = ['hit']
print(Solution().mostCommonWord(paragraph, banned))
