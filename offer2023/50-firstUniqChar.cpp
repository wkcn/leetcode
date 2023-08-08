class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 26> cnts{0};
        for (char c : s) {
            ++cnts[c - 'a'];
        }
        for (char c : s) {
            if (cnts[c - 'a'] == 1) return c;
        }
        return ' ';
    }
};
