class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1, len2 = len(text1), len(text2)
        if len1 < len2:
            return self.longestCommonSubsequence(text2, text1)
        '''
        dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j], dp[i][j] + 1 if text1[i] == text2[j])
        '''
        dp = [0] * (len2 + 1)
        for i in range(len1):
            lt = 0
            for j in range(len2):
                old = dp[j + 1]
                if text1[i] == text2[j]:
                    dp[j + 1] = max(dp[j + 1], lt + 1)
                else:
                    dp[j + 1] = max(dp[j + 1], dp[j])
                lt = old
        return dp[-1]

assert Solution().longestCommonSubsequence("abcde", "ace") == 3
assert Solution().longestCommonSubsequence("abc", "abc") == 3
assert Solution().longestCommonSubsequence("abc", "def") == 0
