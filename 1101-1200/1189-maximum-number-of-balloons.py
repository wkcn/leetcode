class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        bs = Counter('balloon')
        ts = Counter(text)
        return min([ts[k] // v for k, v in bs.items()])
