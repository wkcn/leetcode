class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        const int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int r = 1; r < n; ++r) {
            dp[r] = dp[r - 1] + triangle[r][r];
            for (int c = r - 1; c >= 1; --c) {
                dp[c] = min(dp[c], dp[c-1]) + triangle[r][c];
            }
            dp[0] += triangle[r][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        const int n = triangle.size();
        vector<int> dp = triangle.back();
        for (int r = n - 2; r >= 0; --r) {
          for (int c = 0; c <= r; ++c) {
            dp[c] = min(dp[c], dp[c+1]) + triangle[r][c];
          }
        }
        return dp[0];
    }
};
