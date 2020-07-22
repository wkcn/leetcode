// TODO: 从底向上
// 不申请额外非常数空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int len = triangle.size();
        if (len == 0) return 0;
        vector<int> dp(len);
        dp[0] = triangle[0][0];
        for (int r = 1; r < len; ++r) {
            dp[r] = triangle[r][r] + dp[r-1];
            for (int c = r - 1; c >= 1; --c) {
                dp[c] = triangle[r][c] + min(dp[c], dp[c-1]);
            }
            dp[0] += triangle[r][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
