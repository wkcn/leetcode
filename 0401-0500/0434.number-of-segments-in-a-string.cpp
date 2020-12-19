class Solution {
public:
    int countSegments(string s) {
        int i = 0;
        int cnt = 0;
        while (i < s.size()) {
            for (; i < s.size() && s[i] == ' '; ++i);
            if (i >= s.size()) break;
            ++cnt;
            for (; i < s.size() && s[i] != ' '; ++i);
        }
        return cnt;
    }
};

// 前端计数法
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) ++cnt;
        }
        return cnt;
    }
};
