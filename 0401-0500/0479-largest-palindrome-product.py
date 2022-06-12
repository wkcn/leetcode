class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        for i in range((10 ** n) - 1, 10 ** (n-1) - 1, -1):
            p = int(str(i) + str(i)[::-1])
            # 注意round(x + 0.5)向上取整, 可以写成整数形式：t * t >= p
            for t in range((10 ** n) - 1, max(10 ** (n-1), int(round(p ** 0.5) + 0.5)) - 1, -1):
                if p % t == 0:
                    return p % 1337

print(Solution().largestPalindrome(2))
#print(Solution().largestPalindrome(1))
