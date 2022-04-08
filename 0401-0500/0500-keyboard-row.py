class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        ks = list(map(set, ["qwertyuiop", "asdfghjkl", "zxcvbnm"]))
        def check(word):
            word = word.lower()
            return any(all(map(lambda c: c in k, word)) for k in ks)
        return list(filter(check, words))
