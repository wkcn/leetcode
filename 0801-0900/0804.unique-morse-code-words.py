class Solution(object):
    MS = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        def convert(word):
            return ''.join(Solution.MS[ord(c) - ord('a')] for c in word)
        return len(set(map(convert, words)))
