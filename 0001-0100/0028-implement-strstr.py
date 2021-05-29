class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        prefix = self.get_prefix(needle)
        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                j += 1
                if j >= len(needle):
                    return i + 1 - len(needle)
                i += 1
            else:
                if j == 0:
                    i += 1
                else:
                    j = prefix[j - 1]
        return -1

    def get_prefix_naive(self, needle):
        n = len(needle)
        prefix = [0 for _ in range(n)]
        for i in range(1, n):
            for k in range(i, 0, -1):
                if needle[0:k] == needle[i + 1 - k:i + 1]:
                    prefix[i] = k
                    break
        return prefix

    def get_prefix(self, needle):
        n = len(needle)
        prefix = [0 for _ in range(n)]
        # j for prefix, and i for postfix
        j = 0
        for i in range(1, n):
            # assign prefix[i]
            while j > 0 and needle[i] != needle[j]:
                j = prefix[j - 1]
            if needle[i] == needle[j]:
                j += 1
            prefix[i] = j
        return prefix


haystack = 'aabaabaafa'
needle = 'aabaaf'
print(Solution().strStr(haystack, needle))
assert Solution().strStr('hello', 'll') == 2
assert Solution().strStr('aaaaa', 'bba') == -1
assert Solution().strStr('', '') == 0
