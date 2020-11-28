// 是No. 168题目的反题目
class Solution {
public:
    int titleToNumber(string s) {
        int v = 0;
        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'A';
            v = v * 26 + u + 1;
        }
        return v;
    }
};
