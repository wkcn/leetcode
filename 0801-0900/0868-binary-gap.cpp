class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int last = 32;
        for (int i = 0; i < 32; ++i) {
            if (n & 1) {
                ans = max(ans, i - last);
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};
