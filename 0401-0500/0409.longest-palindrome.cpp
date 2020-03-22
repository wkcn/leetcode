class Solution {
public:
    int longestPalindrome(string s) {
        // 中间可以是单数
        int counts[128] = {0};
        for (char &c : s) ++counts[c];
        int odd = 0;
        int ans = 0;
        for (int i = 0; i < 128; ++i) {
            ans += counts[i] & (~1);
            odd |= counts[i] & 1;
        }
        ans += odd;
        return ans;
    }
};
