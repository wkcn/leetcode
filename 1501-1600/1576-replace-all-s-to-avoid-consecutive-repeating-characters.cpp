class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                char c = i == 0 ? 'a' : ((s[i - 1] - 'a' + 1) % 26) + 'a';
                if (i + 1 < s.size() && c == s[i + 1]) {
                    c = i == 0 ? 'z' : ((s[i - 1] - 'a' + 25) % 26) + 'a';
                }
                s[i] = c;
            }
        }
        return s;
    }
};
