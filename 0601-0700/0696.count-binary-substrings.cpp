class Solution {
public:
    int countBinarySubstrings(string s) {
        const int len = s.size();
        int last = 0;
        int ans = 0;
        int i = 0;
        int j;
        while (i < len) {
            for (j = i + 1; j < len && s[i] == s[j]; ++j);
            // [i, j)
            int u = j - i; i = j;
            ans += min(last, u);
            last = u;
        }
        ans += min(last, j - i);
        return ans;
    }
};
