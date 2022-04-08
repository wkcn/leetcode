class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        sp = text.split()
        ans = []
        for i in range(0, len(sp) - 2):
            if sp[i] == first and sp[i + 1] == second:
                ans.append(sp[i + 2])
        return ans
