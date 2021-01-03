class Solution {
public:
    int trailingZeroes(int n) {
        // 每遇到一个5因子都能加1个
        // 25有两个5因子
        int ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
