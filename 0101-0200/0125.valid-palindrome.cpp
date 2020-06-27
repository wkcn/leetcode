class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && update(i, 1, s));
            while (i < j && update(j, -1, s));
            if (i < j)
                if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    bool update(int &i, int a, string &s) {
        char &c = s[i];
        if (isalpha(c)) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            return false;
        } else if (!isdigit(c)) {
            i += a;
            return true;
        }
        return false;
    }
};
