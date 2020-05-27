// TODO: DP
class Solution {
public:
    bool validPalindrome(string s) {
        const int len = s.size();
        if (len <= 1) return true;
        return validPalindrome(s, 0, len-1, 1);
    }
    bool validPalindrome(const string &s, int i, int j, int times) {
        if (i >= j) return true;
        if (s[i] != s[j]) {
            if (times <= 0) return false;
            return validPalindrome(s, i+1, j, times-1) ||
                validPalindrome(s, i, j-1, times-1);
        }
        ++i;
        --j;
        return validPalindrome(s, i, j, times);
    }
};
