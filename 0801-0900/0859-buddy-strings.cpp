class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        // 交换两个相同的字符
        if (s == goal) {
            unordered_map<char, int> cnts;
            for (char c : s) ++cnts[c];
            for (auto [k, v] : cnts) {
                if (v >= 2) return true;
            }
        }
        // 交换两个不同的字符
        int a = 0;
        int i = -1, j = -1;
        for (; a < s.size(); ++a) {
            if (s[a] != goal[a]) {
                i = a; break;
            }
        }
        for (++a; a < s.size(); ++a) {
            if (s[a] != goal[a]) {
                j = a;
                break;
            }
        }
        for (++a; a < s.size(); ++a) {
            if (s[a] != goal[a]) return false;
        }
        if (i == -1 || j == -1) return false;
        return s[i] == goal[j] && s[j] == goal[i];
    }
};
