import math
def get1snum(i):
    cnt = 0
    while i != 0:
        cnt += 1
        i &= i - 1
    return cnt

def check(i, primes):
    cnt = get1snum(i)
    return primes[cnt]

def get_primes(n):
    primes = [True for _ in range(n + 1)]
    primes[0] = primes[1] = False
    for i in range(2, n + 1):
        if primes[i]:
            for j in range(i + i, n + 1, i):
                primes[j] = False
    return primes

class Solution(object):
    def __init__(self):
        self.primes = get_primes(32)
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        return sum(check(i, self.primes) for i in range(L, R + 1))


if __name__ == '__main__':
    so = Solution()
    print(so.countPrimeSetBits(10, 15))
