class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2: return n
        one = 2
        two = 1
        for i in range(3, n):
            old_one = one
            one = two + one
            two = old_one
        return one + two

print(Solution().climbStairs(2))
print(Solution().climbStairs(3))
