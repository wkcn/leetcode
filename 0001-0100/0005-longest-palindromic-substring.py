class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 0:
            return ""
        m = 2 * n + 3
        T = ['^'] + ['#'] * (m - 2) + ['$']
        i = 2
        for c in s:
            T[i] = c
            i += 2
        L = [0] * m
        C = 0
        R = 0
        cnt = 0
        for i in range(2, m - 2):
            i_mirror = 2 * C - i
            if i_mirror >= 0:
                diff = R - i
                print((i_mirror, i), L[i_mirror], diff)
                if L[i_mirror] < diff:
                    L[i] = L[i_mirror]
                    continue
            t = 1
            while 1:
                if T[i - t] != T[i + t]:
                    break
                t += 1
            cnt += t
            L[i] = t - 1
            C = i
            R = i + L[i]
        print(cnt)
        best_i = 2
        for i in range(2, m - 2):
            if L[i] > L[best_i]:
                best_i = i
        left = (best_i - L[best_i]) // 2
        return s[left:left + L[best_i]] 



#assert Solution().longestPalindrome('babad') in ['bab', 'aba']
#kassert Solution().longestPalindrome('cbbd') == 'bb'
#assert Solution().longestPalindrome('sa') in ['s', 'a']
assert Solution().longestPalindrome('a' * 10) in 'a' * 10

