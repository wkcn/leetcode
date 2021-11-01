class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        e = sorted(str(n))
        for i in range(0, 32):
            t = 1 << i
            if sorted(str(t)) == e:
                return True
        return False
