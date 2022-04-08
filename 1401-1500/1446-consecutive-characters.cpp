class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) return 0;
        char c = s[0];
        int cnt = 1;
        int ans = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
                c = s[i];
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
