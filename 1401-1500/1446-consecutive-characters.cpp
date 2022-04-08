class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) return 0;
        int cnt = 1;
        int ans = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                ans = max(ans, cnt);
                cnt = 1;
            } else ++cnt;
        }
        ans = max(ans, cnt);
        return ans;
    }
};
